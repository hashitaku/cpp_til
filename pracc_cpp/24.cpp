/*range based forと右辺値参照*/
#include<iostream>
#include<vector>

int main(){
    
    std::vector<int> v(10, 1);

    for(auto &&e : v){
        std::cout << e << std::endl;
    }

    for(auto &&e : v){
        e = 2;
    }

    for(const auto &e : v){
        std::cout << e << std::endl;
    }

    int x = 10;
    auto &&r = x;

    r = 20;

    std::cout << x << std::endl;
    
    return 0;
}
