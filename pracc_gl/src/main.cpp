#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <string_view>

// <glew.h> before <GL/gl.h>
#include <GL/glew.h>

#include <GLFW/glfw3.h>

GLboolean print_shader_log(GLuint shader, std::string_view str) {
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if(!status) std::cerr << "compile error: " << str << std::endl;

    GLsizei bufsize;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufsize);

    if(bufsize) {
        // https://yohhoy.hatenadiary.jp/entry/20160327/p1
        // https://qiita.com/yumetodo/items/24d21d97e04977b78b45
        std::basic_string<GLchar> log(bufsize - 1, GLchar{});
        GLsizei len;
        glGetShaderInfoLog(shader, bufsize, &len, log.data());
        std::cout << log << std::endl;
    }

    return status;
}

GLboolean print_program_log(GLuint program) {
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);

    if(!status) std::cerr << "link error" << std::endl;

    GLsizei bufsize;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufsize);

    if(bufsize) {
        std::basic_string<GLchar> log(bufsize - 1, GLchar{});
        GLsizei len;
        glGetProgramInfoLog(program, bufsize, &len, log.data());
        std::cout << log << std::endl;
    }

    return status;
}

std::optional<GLuint> create_program(const char* vsrc, const char* fsrc) {
    const auto program = glCreateProgram();

    if(!(vsrc && fsrc)) return std::nullopt;

    const auto vjob = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vjob, 1, &vsrc, nullptr);
    glCompileShader(vjob);
    if(print_shader_log(vjob, "vertex shader")) {
        glAttachShader(program, vjob);
    }
    glDeleteShader(vjob);

    const auto fjob = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fjob, 1, &fsrc, nullptr);
    glCompileShader(fjob);
    if(print_shader_log(fjob, "fragment shader")) {
        glAttachShader(program, fjob);
    }
    glDeleteShader(fjob);

    glBindAttribLocation(program, 0, "position");
    glBindFragDataLocation(program, 0, "fragment");
    glLinkProgram(program);

    if(print_program_log(program)) return program;

    glDeleteProgram(program);
    return std::nullopt;
}

std::optional<std::string> read_file(const char* path) {
    std::ifstream in(path);

    if(in) {
        return std::string{std::istreambuf_iterator{in},
                           std::istreambuf_iterator<decltype(in)::char_type>{}};
    }

    return std::nullopt;
}

int main() {
    if(!glfwInit()) std::exit(1);

    auto* window = glfwCreateWindow(500, 500, "GLFW", nullptr, nullptr);

    if(!window) {
        glfwTerminate();
        std::exit(1);
    }

    glfwMakeContextCurrent(window);

    if(glewInit()) {
        glfwTerminate();
        std::exit(1);
    }

    std::cout << "OpenGL Version:" << glGetString(GL_VERSION) << std::endl;
    std::cout << "Vendor:" << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer:" << glGetString(GL_RENDERER) << std::endl;

    auto vsrc = read_file("src/main.vert").value();
    auto fsrc = read_file("src/main.frag").value();

    auto program = create_program(vsrc.data(), fsrc.data()).value();

    glClearColor(0.27, 0.34, 0.40, 1.0);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBegin(GL_QUADS);
        glVertex2f(-250, 250);
        glVertex2f(-250, -250);
        glVertex2f(250, -250);
        glVertex2f(250, 0);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(program);
    glfwTerminate();
}
