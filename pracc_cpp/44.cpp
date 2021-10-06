/*コピー関係*/
#include<iostream>

struct S{
    S(){std::cout << "cons" << std::endl;}
    ~S(){std::cout << "dest" << std::endl;}
};

void f(S a){std::cout << "f" << std::endl;}
void g(const S& a){std::cout << "g" << std::endl;}

int main(){

    S a;

    std::cout << "a" << std::endl;
    
    f(a);
    
    return 0;
}
