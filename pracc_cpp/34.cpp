/*参照渡し*/
#include<iostream>

class Num final{
    private:
        int num;
    public:
        Num()noexcept{std::cout << "default" << std::endl;}
        explicit Num(int in)noexcept : num(in){std::cout << "arg 1" << std::endl;}
        Num(const Num &obj){
            num = obj.num;
            std::cout << "copy" << std::endl;
            }
        int get()noexcept{return num;}
        void set(int in)noexcept{num = in;}
};

void f(Num &);
void g(Num);

int main(){

    Num a(10);
    Num b = a;

    f(a);
    f(b);

    // g(a);
    // g(b);
    
    return 0;
}

void f(Num &ref){
    std::cout << ref.get() << std::endl;
}

void g(Num val){
    std::cout << val.get() << std::endl; 
}
