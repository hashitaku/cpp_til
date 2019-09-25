#ifndef INV_DRAW_HPP
#define INV_DRAW_HPP

#include"include/structure.hpp"
#include<GL/freeglut.h>

namespace inv::global{

extern inv::structure::Texture<3> texture;

}


namespace inv::draw{

void point(inv::structure::Vertex<> vertex, inv::structure::RGB<> rgb, double point_size);
void line(inv::structure::Vertex<> begin, inv::structure::Vertex<> end, inv::structure::RGB<> rgb, double line_width);

}

#endif //INV_DRAW_HPP
