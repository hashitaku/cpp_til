/*クラステンプレートの部分特殊化とテンプレートメタ*/
#include<iostream>

template<typename T, typename U>
struct is_same{
    static constexpr auto value = false;
};

template<typename T>
struct is_same<T, T>{
    static constexpr auto value = true;
};

int main(){

    std::cout << std::boolalpha;
    std::cout << is_same<int, int>::value << std::endl;
    std::cout << is_same<int, double>::value << std::endl;

    return 0;
}
