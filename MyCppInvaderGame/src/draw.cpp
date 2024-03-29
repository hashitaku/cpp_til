#include "draw.hpp"

namespace inv::draw {

void point(inv::structure::Point<> vertex, inv::structure::RGB<> rgb, double point_size) {
    auto [r, g, b] = rgb;
    glColor3d(r, g, b);
    glPointSize(point_size);
    glBegin(GL_POINTS);
    glVertex2d(vertex.first, vertex.second);
    glEnd();
}

void line(inv::structure::Point<> begin, inv::structure::Point<> end, inv::structure::RGB<> rgb, double line_width) {
    auto [r, g, b] = rgb;
    glColor3d(r, g, b);
    glLineWidth(line_width);
    glBegin(GL_LINES);
    glVertex2d(begin.first, begin.second);
    glVertex2d(end.first, end.second);
    glEnd();
}

void square(inv::structure::Point<> left_bottom, inv::structure::Point<> left_up, inv::structure::Point<> right_bottom, inv::structure::Point<> right_up, inv::structure::RGB<> rgb) {

    auto [r, g, b] = rgb;
    glColor3d(r, g, b);
    glBegin(GL_QUADS);
    glVertex2d(left_bottom.first, left_bottom.second);
    glVertex2d(left_up.first, left_up.second);
    glVertex2d(right_up.first, right_up.second);
    glVertex2d(right_bottom.first, right_bottom.second);
    glEnd();
}

void enemy(const inv::structure::Enemy& enemy) {
    if(!enemy.is_dead_) {
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, enemy.texture_id_);
        auto [r, g, b] = enemy.color_;
        glColor3d(r, g, b);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);
        glVertex2d(enemy.point_.first, enemy.point_.second);
        glTexCoord2d(0.0, 1.0);
        glVertex2d(enemy.point_.first, enemy.point_.second - enemy.pixel_size_);
        glTexCoord2d(1.0, 1.0);
        glVertex2d(enemy.point_.first + enemy.pixel_size_, enemy.point_.second - enemy.pixel_size_);
        glTexCoord2d(1.0, 0.0);
        glVertex2d(enemy.point_.first + enemy.pixel_size_, enemy.point_.second);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}

void enemy(const inv::structure::Enemy_set<5, 10>& set) {
    for(const auto& v : inv::global::enemy_set.set_) {
        for(const auto& e : v) {
            inv::draw::enemy(e);
        }
    }
}

void menu(unsigned int menu_texture_id, inv::structure::RGB<> back_color) {
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, menu_texture_id);
    auto [r, g, b] = back_color;
    glColor3d(r, g, b);
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

void number(uint64_t num, inv::structure::Point<> point, inv::structure::RGB<> rgb) {
    std::array<char, 20> str = {};
    auto [end_ptr, ec]       = std::to_chars(str.data(), str.data() + str.size(), num, 10);

    if(ec == std::errc::value_too_large) {
        std::cerr << std::make_error_condition(ec).message() << std::endl;
        std::exit(1);
    }

    auto [r, g, b] = rgb;
    glColor3d(r, g, b);
    glRasterPos2d(point.first, point.second);

    for(auto it = str.data(); it != end_ptr; it++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it);
    }
}

void string(const std::string& str, inv::structure::Point<> point, inv::structure::RGB<> rgb) {
    auto [r, g, b] = rgb;
    glColor3d(r, g, b);
    glRasterPos2d(point.first, point.second);

    for(const auto& c : str) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

} // namespace inv::draw
