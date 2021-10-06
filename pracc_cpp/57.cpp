/*odr used*/
#include<iostream>

struct A{
    void hoge() const {
        std::cerr << "hoge" << std::endl;
    }

    static void huga(){
        std::cerr << "huga" << std::endl;
    }
};

struct B{
    static const A a;

    void hoge(){
        a.hoge();
        a.huga();
    }
};

int main(){

    B a;

    a.hoge();

    return 0;
}
