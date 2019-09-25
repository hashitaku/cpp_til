#ifndef INV_STRUCTURE_HPP
#define INV_STRUCTURE_HPP

#include<tuple>
#include<utility>
#include<array>
#include<filesystem>

namespace inv::structure{

enum class Window_number : uint8_t{
    Menu,
    Game,
    Result
};

template<typename Tp = double>
using Point = std::pair<Tp, Tp>;

template<typename Tp = double>
using RGB = std::tuple<Tp, Tp, Tp>;

template<size_t N>
using Texture = std::array<std::pair<std::filesystem::path, unsigned int>, N>;

template<typename Tp = double>
class Own final{
    private:
        size_t life;
        unsigned int texture_id;
        inv::structure::Point<Tp> point;

    public:
        Own() = delete; //HPと座標を持たずに存在しない
        Own(size_t hp, unsigned int id, inv::structure::Point<Tp> xy) noexcept : life(hp), texture_id(id), point(xy) {}

        bool is_dead() const noexcept { return life == 0; }
        auto get_id() const noexcept { return texture_id; }
        auto get_p() const noexcept { return point; }
        auto get_x() const noexcept { return point.first; }
        auto get_y() const noexcept { return point.second; }
        void add_move(Tp x, Tp y) noexcept {
            point.first += x;
            point.second += y;
        }
};

template<typename Tp = double>
class Enemy final{
    private:
        bool dead;
        unsigned int texture_id;
        inv::structure::Point<Tp> point;

    public:
        Enemy() = delete; //座標を持たずに存在はしない
        Enemy(unsigned int id, inv::structure::Point<Tp> xy) noexcept : dead(false), texture_id(id), point(xy) {}

        bool is_dead() const noexcept { return dead; }
        auto get_id() const noexcept { return texture_id; }
        auto get_p() const noexcept { return point; }
        auto get_x() const noexcept { return point.first; }
        auto get_y() const noexcept { return point.second; }
        void add_move(Tp x, Tp y) noexcept {
            point.first += x;
            point.second += y;
        }
};

}

#endif //INV_STRUCTURE_HPP
