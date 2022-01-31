/*演算子自動生成c++2a*/
#include <iostream>

struct A {
    int val;
};

bool operator==(const A& x, const A& y) {
    return x.val == y.val;
}

bool operator==(const A& x, int y) {
    return x.val == y;
}

int main() {
    auto a = A{1};

    std::cout << std::boolalpha
              << (a == a) << '\n'
              << (a != a) << '\n'
              << (a == 1) << '\n'
              << (1 == a) << std::endl;
}
