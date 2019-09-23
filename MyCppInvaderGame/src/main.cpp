#include<array>
#include<filesystem>
#include<GL/freeglut.h>

#include"include/constant.hpp"
#include"include/system.hpp"

namespace inv::global{

std::array<std::pair<std::filesystem::path, unsigned int>, 3> texture = {{{"texture/inv_1.png", 0},
																 		  {"texture/inv_2.png", 0},
																 		  {"texture/menu.png", 0}
																		}};

}

int main(int argc, char* argv[]){

	glutInit(&argc, argv);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	glutInitWindowPosition(inv::constant::window_position_x, inv::constant::window_position_y);
	glutInitWindowSize(inv::constant::window_size_width, inv::constant::window_size_height);
	glutCreateWindow(inv::constant::window_name);

	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	for(auto&& [filename, id] : inv::global::texture){
		inv::sys::load_tex(filename, &id);
	}

	for(const auto& e : inv::global::texture){
		std::cout << e.second << std::endl;
	}

	glutReshapeFunc(inv::sys::resize);

	// glutDisplayFunc(display);

	glutMainLoop();

	for(auto&& e : inv::global::texture){
		glDeleteTextures(1, &e.second);
	}

	return 0;
}
