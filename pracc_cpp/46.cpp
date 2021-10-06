/*構造化束縛をキャプチャ*/
#include<iostream>
#include<tuple>

int main(){
    
    std::tuple<int, int> t = std::make_tuple(1, 2);

    auto [a, b] = t;

    std::cout << a << std::endl << b << std::endl;

    auto f = [a](){std::cout << a << std::endl;};

    f();
    
    return 0;
}
