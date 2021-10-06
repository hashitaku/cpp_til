/*バブルソート*/
#include<iostream>

int main(){

    int array[10];
    int tmp = 0;

    for(int i = 0; i < 10; i++){
        std::cin >> array[i];
    }

    for(int i = 0; i < 10; i++){
        for(int j = 10 - 1; j > i; j--){
            if(array[i] > array[j]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        std::cout << array[i] << std::endl;
    }

    return 0;
}
