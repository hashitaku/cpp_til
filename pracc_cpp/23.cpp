/*演算子オーバロード*/
#include<iostream>

class MyPair{
    private:
        int num1;
        int num2;
    public:
        MyPair(){}

        MyPair(int in1, int in2) :num1(in1), num2(in2){

        }

        int ave(){
            return (num1 + num2) / 2;
        }

        void show(){
            std::cout << num1 << " " << num2 << std::endl;
        }

        void operator()(){
            std::cout << num1 << " " << num2 << std::endl;
        }

        MyPair& operator+=(const MyPair& in){
            num1 += in.num1;
            num2 += in.num2;
            return *this;
        }
};

int main(){

    MyPair obj(10, 20);
    MyPair obj2(30, 40);

    obj();
    obj2();
    // std::cout << obj.ave() << std::endl;
    // std::cout << obj2.ave() << std::endl;

    obj += obj2;

    obj.show();

    return 0;
}
