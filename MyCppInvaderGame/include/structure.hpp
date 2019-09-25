#ifndef INV_STRUCTURE_HPP
#define INV_STRUCTURE_HPP

#include<tuple>
#include<utility>
#include<array>
#include<filesystem>

namespace inv::structure{

template<typename Tp = double>
using Vertex = std::pair<Tp, Tp>;

template<typename Tp = double>
using RGB = std::tuple<Tp, Tp, Tp>;

template<size_t N>
using Texture = std::array<std::pair<std::filesystem::path, unsigned int>, N>;

}

#endif //INV_STRUCTURE_HPP
