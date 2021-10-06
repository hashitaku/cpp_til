/*クラスの一時オブジェクト*/
#include<iostream>
#include<vector>

template<typename T>
void f(T);

int main(){
    
    f(std::vector<int>(10, 0));
    
    return 0;
}

template<typename T>
void f(T a){
    std::cout << a.size() << std::endl;
}
