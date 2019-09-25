#include"include/draw.hpp"

namespace inv::draw{

void point(inv::structure::Vertex<> vertex, inv::structure::RGB<> rgb, double point_size){
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glPointSize(point_size);
	glBegin(GL_POINTS);
	glVertex2d(vertex.first, vertex.second);
	glEnd();
}

void line(inv::structure::Vertex<> begin, inv::structure::Vertex<> end, inv::structure::RGB<> rgb, double line_width){
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glLineWidth(line_width);
	glBegin(GL_LINES);
	glVertex2d(begin.first, begin.second);
	glVertex2d(end.first, end.second);
	glEnd();
}

}
