#ifndef INV_SYSTEM_HPP
#define INV_SYSTEM_HPP

#include "GL/freeglut.h"
#include "constant.hpp"
#include "draw.hpp"
#include "stb_image.hpp"
#include "structure.hpp"

#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace inv::global {

extern inv::structure::Texture<3>       texture;
extern inv::structure::Window_number    window_number;
extern inv::structure::Point<>          mouse_point;
extern inv::structure::Enemy_set<5, 10> enemy_set;

} // namespace inv::global

namespace inv::sys {

void debug_log();
void load_tex(const std::filesystem::path& filename, unsigned int* id);

/*call back*/
void resize(int width, int height);
void display();
void motion([[maybe_unused]] int x);
void mouse(int x, int y);
void mouse_button(int button, int state, [[maybe_unused]] int x, [[maybe_unused]] int y);

} // namespace inv::sys

#endif //INV_SYSTEM_HPP
