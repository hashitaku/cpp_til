#ifndef INV_DRAW_HPP
#define INV_DRAW_HPP

#include<iostream>
#include<charconv>
#include<system_error>
#include<GL/freeglut.h>

#include"include/structure.hpp"
#include"include/constant.hpp"

namespace inv::global{

extern inv::structure::Texture<3> texture;

}


namespace inv::draw{

void point(inv::structure::Point<> vertex, inv::structure::RGB<> rgb, double point_size);
void line(inv::structure::Point<> begin, inv::structure::Point<> end, inv::structure::RGB<> rgb, double line_width);
void square(inv::structure::Point<> left_bottom, inv::structure::Point<> left_up,
            inv::structure::Point<> right_bottom, inv::structure::Point<> right_up, inv::structure::RGB<> rgb);
void menu(inv::structure::RGB<> back_color);
void number(uint64_t num, inv::structure::Point<> point, inv::structure::RGB<> rgb);
void string(std::string str, inv::structure::Point<> point, inv::structure::RGB<> rgb);

}

#endif //INV_DRAW_HPP
