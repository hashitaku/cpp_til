#ifndef INV_STRUCTURE_HPP
#define INV_STRUCTURE_HPP

#include <array>
#include <filesystem>
#include <tuple>
#include <utility>

namespace inv::structure {

enum class Window_number : uint8_t {
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

struct Own final {
    size_t                        life_;
    unsigned int                  texture_id_;
    inv::structure::Point<double> point_;

    Own() = delete; //HPと座標を持たずに存在しない
    Own(size_t hp, unsigned int id, inv::structure::Point<double> xy) noexcept :
        life_(hp),
        texture_id_(id),
        point_(xy) {}
};

struct Enemy final {
    bool                    is_dead_ = false;
    unsigned int            texture_id_;
    inv::structure::Point<> point_; // upper left points
    inv::structure::RGB<>   color_;

    static constexpr size_t pixel_size_ = 32;

    Enemy() noexcept :
        is_dead_(true) {}
    Enemy(unsigned int id, inv::structure::Point<> xy, inv::structure::RGB<> rgb) noexcept :
        texture_id_(id),
        point_(xy),
        color_(rgb) {}
};

template<size_t N, size_t M>
struct Enemy_set final {
    std::array<std::array<inv::structure::Enemy, M>, N> set_;
    bool                                                is_move_left_ = true;

    Enemy_set(size_t window_width, size_t window_height) {
        this->init(window_width, window_height);
    }

    void init(size_t window_width, size_t window_height) {
        using namespace inv;

        for(size_t i = 0; i < N; i++) {
            for(size_t j = 0; j < M; j++) {
                if(i % 2 == 0) {
                    set_[i][j] = {1u,
                                  {(window_width / M / 2) * j,
                                   (window_height / 2) - (window_height / N / 4) * i},
                                  structure::RGB<> {1.0, 1.0, 0.0}};
                } else {
                    set_[i][j] = {2u,
                                  {(window_width / M / 2) * j,
                                   (window_height / 2) - (window_height / N / 4) * i},
                                  structure::RGB<> {0.0, 1.0, 1.0}};
                }
            }
        }
    }
};

} // namespace inv::structure

#endif //INV_STRUCTURE_HPP
