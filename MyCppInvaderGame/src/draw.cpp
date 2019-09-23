#include"include/draw.hpp"

namespace inv::draw{

void line(std::pair<double, double> begin, std::pair<double, double> end){
	glColor3d(0.0, 1.0, 1.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2d(begin.first, begin.second);
	glVertex2d(end.first, end.second);
	glEnd();
}

}
