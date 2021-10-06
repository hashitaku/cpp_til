/*コピーコンストラクタとコピー代入演算子*/
/*f()のコピーの省略*/
#include<iostream>

class Num{
    private:
        int num;
    public:
        Num(){std::cout << u8"デフォルトコンストラクタ" << std::endl; }
        Num(int a) : num(a) { std::cout << u8"引数つきコンストラクタ" << std::endl; }
        Num(const Num& in) : num(in.num) { std::cout << u8"コピーコンストラクタ" << std::endl; }
        Num& operator=(const Num& in){
            num = in.num;
            std::cout << u8"コピー代入演算子" << std::endl;
            return *this;
        }
        ~Num(){ std::cout << u8"デストラクタ" << std::endl; }
};

Num f(Num);
Num f();

int main(){
    
    Num a;
    // Num b(10);
    // Num c(a);
    Num d;
    d = a;
    // Num e = f(a);
    // Num g = f();
    
    return 0;
}

Num f(Num in){
    std::cout << "check" << std::endl;
    return in;
}

Num f(){
    std::cout << "check" << std::endl;
    return Num();
}
