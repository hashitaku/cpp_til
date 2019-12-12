#include"GL/freeglut.h"

#include"structure.hpp"
#include"constant.hpp"
#include"system.hpp"

namespace inv::global{

inv::structure::Texture<3> texture = {{{"texture/inv_1.png", 0},
									   {"texture/inv_2.png", 0},
									   {"texture/menu.png", 0}
									 }};

inv::structure::Window_number window_number = inv::structure::Window_number::Menu;
inv::structure::Point<> mouse_point;

}

int main(int argc, char* argv[]){

	glutInit(&argc, argv);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	glutInitWindowPosition(inv::constant::window_position_x, inv::constant::window_position_y);
	glutInitWindowSize(inv::constant::window_size_width, inv::constant::window_size_height);
	glutCreateWindow(inv::constant::window_name);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	for(auto&& [filename, id] : inv::global::texture){
		inv::sys::load_tex(filename, &id);
	}

	glutReshapeFunc(inv::sys::resize);
	glutPassiveMotionFunc(inv::sys::mouse);
	glutMotionFunc(inv::sys::mouse);
	glutMouseFunc(inv::sys::mouse_button);
	glutDisplayFunc(inv::sys::display);
	glutTimerFunc(inv::constant::sleep_milli_time, inv::sys::motion, 0);

	inv::sys::debug_log();

	glutMainLoop();

	for(auto&& e : inv::global::texture){
		glDeleteTextures(1, &e.second);
	}

	return 0;
}
