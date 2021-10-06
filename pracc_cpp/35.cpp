/*テンプレートの特殊化*/
#include<iostream>

template<typename T>
void f(T a){
    std::cout << "not int:" << a << std::endl;
}

template<>
void f(int a){
    std::cout << "int:" << a << std::endl;
}

int main(){
    
    f(1.2);
    f(10);
    
    return 0;
}
