/*ポインタとイテレータ*/
#include<iostream>

int main(){

    using std::begin;
    using std::end;

    int array[10];
    int *pA;

    pA = array;

    for(int i = 0; i < 10; i++){
        std::cin >> array[i];
    }

    for(int i = 0; i < 10; i++){
        std::cout << pA[i] << std::endl;
    }

    for(int *i = begin(array); i != end(array); i++){
        std::cout << *i << std::endl;
    }

    return 0;
}
