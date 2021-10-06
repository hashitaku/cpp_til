/*名前空間*/
#include<iostream>

//using namespace std; これはエラー

namespace my_namespace{

    void cout(){
        std::cout << "test" << std::endl;
    }
}

int main(){

    my_namespace::cout();

    return 0;
}
