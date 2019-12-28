#ifndef INV_DRAW_HPP
#define INV_DRAW_HPP

#include "GL/freeglut.h"
#include "constant.hpp"
#include "structure.hpp"

#include <charconv>
#include <iostream>
#include <system_error>

namespace inv::global {

extern inv::structure::Texture<3>       texture;
extern inv::structure::Enemy_set<5, 10> enemy_set;

} // namespace inv::global

namespace inv::draw {

void point(inv::structure::Point<> vertex, inv::structure::RGB<> rgb, double point_size);
void line(inv::structure::Point<> begin, inv::structure::Point<> end, inv::structure::RGB<> rgb, double line_width);
void square(inv::structure::Point<> left_bottom, inv::structure::Point<> left_up, inv::structure::Point<> right_bottom, inv::structure::Point<> right_up, inv::structure::RGB<> rgb);
void enemy(const inv::structure::Enemy& enemy);
void enemy(const inv::structure::Enemy_set<5, 10>& set);
void menu(unsigned int menu_texture_id, inv::structure::RGB<> back_color);
void number(uint64_t num, inv::structure::Point<> point, inv::structure::RGB<> rgb);
void string(const std::string& str, inv::structure::Point<> point, inv::structure::RGB<> rgb);

} // namespace inv::draw

#endif //INV_DRAW_HPP
