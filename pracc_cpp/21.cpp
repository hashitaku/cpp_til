/*左辺値参照*/
#include<iostream>

int main(){
    
    int a = 10;

    int &ra = a;

    std::cout << "a:" << a << std::endl;
    std::cout << "ra:" << ra << std::endl;

    ra = 20;

    std::cout << "a:" << a << std::endl;
    std::cout << "ra:" << ra << std::endl;
    
    return 0;
}