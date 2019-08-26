#include"include/system.hpp"

namespace inv::sys{

void resize(int width, int height){
    glutReshapeWindow(inv::constant::window_size_width, inv::constant::window_size_height);
}

}
