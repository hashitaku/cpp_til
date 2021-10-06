/*高階関数とカリー化*/

#include<iostream>

constexpr auto plus(int x, int y){ //従来の足し算
    return x + y;
}

constexpr auto curried_plus(int x){ //カリー化された足し算
    return [x](int a) constexpr { return x + a; };
}

constexpr auto plus_three = curried_plus(3); //部分適用

int main(){

    std::cout << plus(3, 5) << std::endl;
    
    std::cout << curried_plus(3)(5) << std::endl;

    std::cout << plus_three(5) << std::endl;
    
    return 0;
}

