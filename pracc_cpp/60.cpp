/*concepts*/
#include <iostream>
#include <concepts>

template<typename T>
concept C = requires(T a) { 
                a + a;
                a - a;
            };

struct Hoge {
    int a;
    
    Hoge operator+(Hoge x) {
        this->a += x.a;
        return *this;
    }
};

struct Huga {
    int a;

    Huga operator+(Huga x) {
        this->a += x.a;
        return *this;
    }

    Huga operator-(Huga x) {
        this->a -= x.a;
        return *this;
    }
};

template<C T>
T f(T a, T b) {
    return a + b;
}


int main() {

    Hoge a{10}, b{20};
    Huga x{10}, y{20};

    // std::cout << f(a, b).a << std::endl;
    std::cout << f(x, y).a << std::endl;

    return 0;
}
