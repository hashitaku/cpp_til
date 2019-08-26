#include<GL/freeglut.h>

#include"include/constant.hpp"
#include"include/system.hpp"

int main(int argc, char* argv[]){

	glutInit(&argc, argv);
	
	glutInitWindowPosition(inv::constant::window_position_x, inv::constant::window_position_y);
	glutInitWindowSize(inv::constant::window_size_width, inv::constant::window_size_height);
	glutCreateWindow(inv::constant::window_name);

	glutInitDisplayMode(GLUT_RGBA);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutReshapeFunc(inv::sys::resize);

	// glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
