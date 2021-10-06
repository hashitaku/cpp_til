/*一様初期化*/
#include<iostream>
#include<random>

int main(){
    
    std::mt19937_64 gen(std::random_device{}());

    // auto tmp = std::random_device();

    std::mt19937_64 gen2((std::random_device())());
    // std::mt19937_64 gen2(tmp());

    std::cout << gen() << std::endl;
    std::cout << gen2() << std::endl;
    
    return 0;
}
