/*名前空間*/
#include<iostream>

namespace my{
    void hello(void);
}

int main(){

    my::hello();

    return 0;
}

void my::hello(void){
    std::cout << "hello" << std::endl;
}
