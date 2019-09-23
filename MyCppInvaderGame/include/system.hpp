#ifndef INV_SYSTEM_HPP
#define INV_SYSTEM_HPP

#include<filesystem>
#include<iostream>
#include<GL/freeglut.h>

#include"include/constant.hpp"
#include"include/stb_image.hpp"

namespace inv::sys{

void resize([[maybe_unused]]int width, [[maybe_unused]]int height);
void load_tex(const std::filesystem::path& filename, unsigned int* id);

}

#endif //INV_SYSTEM_HPP
