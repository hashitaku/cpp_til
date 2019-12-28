#include "system.hpp"

namespace inv::sys {

void debug_log() {
    std::ofstream log("log.txt");

    for(const auto& [filename, id] : inv::global::texture) {
        log << "filename:" << filename << ' ' << "id:" << id << std::endl;
    }

    log << "OpenGL Version:" << glGetString(GL_VERSION) << std::endl;
    log << "Vendor:" << glGetString(GL_VENDOR) << std::endl;
    log << "Renderer:" << glGetString(GL_RENDERER) << std::endl;

    auto s = glGetString(GL_EXTENSIONS);
    log << "-----OpenGL Extensions-----" << std::endl;
    for(size_t i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ') {
            log << '\n';
        } else {
            log << s[i];
        }
    }
    log << "--------------------------" << std::endl;

    auto error = glGetError();
    do {
        if(error == GL_NO_ERROR) {
            log << "no error" << std::endl;
        } else {
            log << error << std::endl;
        }
        error = glGetError();
    } while(error != GL_NO_ERROR);
}

void load_tex(const std::filesystem::path& filename, unsigned int* id) {

    if(id == nullptr) {
        std::cerr << "load_tex *id is nullptr" << std::endl;
        std::exit(1);
    }

    glGenTextures(1, id);

    int width, height, channel;

    auto texture = stbi_load(filename.string().c_str(), &width, &height, &channel, STBI_default);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, *id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);

    stbi_image_free(texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glLoadIdentity();
    glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, -1.0, 1.0);
    glutReshapeWindow(inv::constant::window_size_width, inv::constant::window_size_height);
}

void display() {
    if(inv::global::window_number == inv::structure::Window_number::Menu) {
        glClear(GL_COLOR_BUFFER_BIT);
        inv::draw::menu(inv::global::texture.at(2).second, inv::constant::Color<>::BLACK);
        glutSwapBuffers();
    } else if(inv::global::window_number == inv::structure::Window_number::Game) {
        glClear(GL_COLOR_BUFFER_BIT);

        /*スコア、背景描画*/
        inv::draw::square({inv::constant::window_size_width / -2.0, inv::constant::window_size_height / -2.0},
                          {inv::constant::window_size_width / -2.0, inv::constant::gameover_line},
                          {inv::constant::window_size_width / 2.0, inv::constant::window_size_height / -2.0},
                          {inv::constant::window_size_width / 2.0, inv::constant::gameover_line},
                          inv::constant::Color<>::GREY);
        inv::draw::string("Point:", {-320.0, -315.0}, inv::constant::Color<>::BLUE);
        // inv::draw::number(point, {-260.0,-315.0}, {1.0, 1.0, 1.0});
        inv::draw::string("HP:", {260.0, -315.0}, inv::constant::Color<>::BLUE);
        // inv::draw::number(hodai_life, {300.0, -315.0}, {1.0, 1.0, 1.0});

        /*自機描画*/
        inv::draw::square({inv::global::mouse_point.first - 10.0, inv::constant::gameover_line},
                          {inv::global::mouse_point.first - 10.0, inv::constant::gameover_line + 10.0},
                          {inv::global::mouse_point.first + 10.0, inv::constant::gameover_line},
                          {inv::global::mouse_point.first + 10.0, inv::constant::gameover_line + 10.0},
                          inv::constant::Color<>::YELLOW);

        /*敵描画*/
        inv::draw::enemy(inv::global::enemy_set);

        glutSwapBuffers();
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
        glutSwapBuffers();
    }
}

void motion([[maybe_unused]] int x) {
    if(inv::global::window_number == inv::structure::Window_number::Menu) {
        inv::global::enemy_set.init(inv::constant::window_size_width, inv::constant::window_size_height);
    }

    glutPostRedisplay();
    glutTimerFunc(inv::constant::sleep_milli_time, motion, 0);
}

void mouse(int x, int y) {
    inv::global::mouse_point.first  = x - inv::constant::window_size_width / 2.0;
    inv::global::mouse_point.second = inv::constant::window_size_height / 2.0 - y;
}

void mouse_button(int button, int state, [[maybe_unused]] int x, [[maybe_unused]] int y) {
    using namespace inv::global;
    using namespace inv::structure;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && window_number == Window_number::Menu) {
        window_number = Window_number::Game;
    } else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && window_number == Window_number::Result) {
        window_number = Window_number::Menu;
    }
}

} // namespace inv::sys
