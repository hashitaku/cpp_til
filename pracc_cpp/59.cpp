#include <iostream>
#include <string>
#include <vector>
#include <ranges>

int main() {

    namespace rv = std::ranges::views;
    using std::literals::string_literals::operator""s, std::literals::string_view_literals::operator""sv;

    constexpr auto s = "hello cpp world !!"sv;

    for(const auto& e : s | rv::split(' ') ) {
        for(const auto& c : e) {
            std::cout << c;
        }
        std::cout << '\n';
    }

    return 0;
}
