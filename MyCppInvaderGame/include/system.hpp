#ifndef INV_SYSTEM_HPP
#define INV_SYSTEM_HPP

#include<filesystem>
#include<iostream>
#include<fstream>

#include"GL/freeglut.h"

#include"structure.hpp"
#include"constant.hpp"
#include"stb_image.hpp"
#include"draw.hpp"

namespace inv::global{

extern inv::structure::Texture<3> texture;
extern inv::structure::Window_number window_number;
extern inv::structure::Point<> mouse_point;

}

namespace inv::sys{

void debug_log();
void resize(int width, int height);
void load_tex(const std::filesystem::path& filename, unsigned int* id);
void display();
void motion([[maybe_unused]]int x);
void mouse(int x, int y);
void mouse_button(int button, int state, [[maybe_unused]]int x, [[maybe_unused]]int y);

}

#endif //INV_SYSTEM_HPP
