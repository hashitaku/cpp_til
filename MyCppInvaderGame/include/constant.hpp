#ifndef INV_CONSTANT_HPP
#define INV_CONSTANT_HPP

#include "structure.hpp"

#include <cstddef>

namespace inv::constant {

constexpr size_t            window_position_x  = 0;
constexpr size_t            window_position_y  = 0;
constexpr size_t            window_size_width  = 640;
constexpr size_t            window_size_height = 640;
constexpr size_t            sleep_milli_time   = 15;
constexpr const char* const window_name        = "MyInvaderGame";
constexpr double            gameover_line      = -290.0;

template<typename Tp = double>
struct Color {
    static constexpr inv::structure::RGB<Tp> BLACK     = {0.0, 0.0, 0.0};
    static constexpr inv::structure::RGB<Tp> RED       = {1.0, 0.0, 0.0};
    static constexpr inv::structure::RGB<Tp> GREEN     = {0.0, 1.0, 0.0};
    static constexpr inv::structure::RGB<Tp> LIGH_BLUE = {0.0, 1.0, 1.0};
    static constexpr inv::structure::RGB<Tp> BLUE      = {0.0, 0.0, 1.0};
    static constexpr inv::structure::RGB<Tp> PINK      = {1.0, 0.0, 1.0};
    static constexpr inv::structure::RGB<Tp> YELLOW    = {1.0, 1.0, 0.0};
    static constexpr inv::structure::RGB<Tp> WHITE     = {1.0, 1.0, 1.0};
    static constexpr inv::structure::RGB<Tp> GREY      = {0.5, 0.5, 0.5};

    // static constexpr inv::structure::RGB<Tp> MENU_COLOR = {0.03922, 0.1961, 0.2784};
};

} // namespace inv::constant

#endif //INV_CONSTANT_HPP
