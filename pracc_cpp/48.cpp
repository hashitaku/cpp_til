/*型比較*/
#include<iostream>
#include<tuple>
#include<type_traits>

template<typename... Actual>
struct Hoge{
    template<typename... Comp>
    constexpr static bool check(){
        return std::is_same_v<std::tuple<Actual...>, std::tuple<Comp...>>;
    }

    template<typename... Comp>
    struct Piyo{
        constexpr static bool value = std::is_same_v<std::tuple<Actual...>, std::tuple<Comp...>>;
    };
};


int main(){
    
    Hoge<int, double> a;

    std::cout << std::boolalpha << a.check<int, double>() << std::endl;
    std::cout << std::boolalpha << a.check<double, int>() << std::endl;

    std::cout << std::boolalpha << Hoge<int, double>::Piyo<int, double>::value << std::endl;
    
    return 0;
}
