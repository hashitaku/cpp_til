#include<array>
#include<iostream>
#include<GL/freeglut.h>

#include"include/constant.hpp"
#include"include/system.hpp"

namespace inv::global{

std::array<unsigned int, 3> texture_id = {};

}

int main(int argc, char* argv[]){

	glutInit(&argc, argv);
	
	glutInitWindowPosition(inv::constant::window_position_x, inv::constant::window_position_y);
	glutInitWindowSize(inv::constant::window_size_width, inv::constant::window_size_height);
	glutCreateWindow(inv::constant::window_name);

	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	inv::sys::load_tex("texture/inv_1.png", &inv::global::texture_id[0]);
	inv::sys::load_tex("texture/inv_2.png", &inv::global::texture_id[1]);
	inv::sys::load_tex("texture/menu.png", &inv::global::texture_id[2]);

	glutReshapeFunc(inv::sys::resize);

	// glutDisplayFunc(display);

	glutMainLoop();

	glDeleteTextures(3, inv::global::texture_id.data());

	return 0;
}
