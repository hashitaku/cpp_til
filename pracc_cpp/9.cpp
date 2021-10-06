/*<algorithm>の使用(cinへのポインタ)*/
#include<iostream>
#include<algorithm>
#include<array>

int main(){

    using std::begin;
    using std::end;

    std::array<int, 10>x = {};

    for(int *i = begin(x); i != end(x); i++){
        std::cin >> *i;
    }

    std::sort(begin(x), end(x));

    for(int *i = begin(x); i != end(x); i++){
        std::cout << *i << std::endl;
    }


    return 0;
}
