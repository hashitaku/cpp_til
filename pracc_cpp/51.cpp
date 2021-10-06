/*ムーブセマンティクス */
#include<iostream>

class Hoge final{
    private:
        int* ptr;
    public:
        Hoge() : ptr(nullptr) {}

        Hoge(int a) : ptr(new int(a)) {
            std::cout << a << ":コンストラクタ" << std::endl;
        }

        Hoge(const Hoge& a){
            this->ptr = new int(a.get());
            std::cout << *this->ptr << ":コピーコンストラクタ" << std::endl;
        }

        Hoge(Hoge&& a){
            this->ptr = a.ptr;
            a.ptr = nullptr;
            std::cout << *this->ptr << ":ムーブコンストラクタ" << std::endl;
        }

        Hoge& operator=(const Hoge& a){
            delete this->ptr;
            this->ptr = new int(a.get());
            std::cout << "コピー代入演算子" << std::endl;
            return *this;
        }

        Hoge& operator=(Hoge&& a){
            delete this->ptr;
            this->ptr = a.ptr;
            a.ptr = nullptr;
            std::cout << "ムーブ代入演算子" << std::endl;
            return *this;
        }

        ~Hoge(){
            std::cout << "デストラクタ" << std::endl;
            delete ptr;
        }

        int get() const { return *ptr; }
        void print() const { std::cout << ptr << std::endl; }
};

Hoge f(){
    Hoge ret(2);
    ret.print();
    return ret;
}

void g(Hoge&& a){
    a.print();
}

int main(){
    
    auto a = f();

    a.print();

    g(Hoge(1));

    return 0;
}
