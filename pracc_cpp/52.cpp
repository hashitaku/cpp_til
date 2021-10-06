/*std::functionのオーバーヘッド */
#include<iostream>
#include<chrono>
#include<functional>

template<typename T>
auto f(T func){ return func(); }

auto g(std::function<int()> func){ return func(); }

int main(){

{
    auto begin = std::chrono::high_resolution_clock{}.now();
    f([](){ return 1; });
    auto end = std::chrono::high_resolution_clock{}.now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
}

{
    auto begin = std::chrono::high_resolution_clock{}.now();
    g([](){ return 1; });
    auto end = std::chrono::high_resolution_clock{}.now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
}
   
    return 0;
}
