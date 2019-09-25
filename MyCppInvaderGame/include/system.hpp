#ifndef INV_SYSTEM_HPP
#define INV_SYSTEM_HPP

#include<filesystem>
#include<iostream>
#include<GL/freeglut.h>

#include"include/constant.hpp"
#include"include/stb_image.hpp"
#include"include/draw.hpp"

namespace inv::global{



}

namespace inv::sys{

void resize(int width, int height);
void load_tex(const std::filesystem::path& filename, unsigned int* id);
void display();
void motion([[maybe_unused]]int x);

}

#endif //INV_SYSTEM_HPP
