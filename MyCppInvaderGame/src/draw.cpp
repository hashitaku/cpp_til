#include"include/draw.hpp"

namespace inv::draw{

void point(inv::structure::Point<> vertex, inv::structure::RGB<> rgb, double point_size){
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glPointSize(point_size);
	glBegin(GL_POINTS);
	glVertex2d(vertex.first, vertex.second);
	glEnd();
}

void line(inv::structure::Point<> begin, inv::structure::Point<> end, inv::structure::RGB<> rgb, double line_width){
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glLineWidth(line_width);
	glBegin(GL_LINES);
	glVertex2d(begin.first, begin.second);
	glVertex2d(end.first, end.second);
	glEnd();
}

void menu(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, inv::global::texture.at(2).second);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(inv::constant::window_size_width / -2.0, inv::constant::window_size_height / 2.0);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(inv::constant::window_size_width / -2.0, inv::constant::window_size_height / -2.0);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(inv::constant::window_size_width / 2.0, inv::constant::window_size_height / -2.0);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(inv::constant::window_size_width / 2.0, inv::constant::window_size_height / 2.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void number(uint64_t num, inv::structure::Point<> point, inv::structure::RGB<> rgb){
	std::array<char, 20> str = {};
	auto [end_ptr, ec] = std::to_chars(str.begin(), str.end(), num, 10);

	if(ec == std::errc::value_too_large){
		std::cerr << std::make_error_condition(ec).message() << std::endl;
		std::exit(1);
	}
	
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glRasterPos2d(point.first, point.second);

	for(auto it = str.begin(); it != end_ptr; it++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it);
	}
}

void string(std::string str, inv::structure::Point<> point, inv::structure::RGB<> rgb){
	auto [r, g, b] = rgb;
	glColor3d(r, g, b);
	glRasterPos2d(point.first, point.second);
	
	for(const auto& c : str){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}

}
