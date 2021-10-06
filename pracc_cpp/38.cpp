/*テンプレートメタ*/
#include<iostream>

template<typename T>
struct Util{
    using value_type = const T;
};

int main(){

    Util<int>::value_type a = 10;

    std::cout << a << std::endl;
    
    return 0;
}
