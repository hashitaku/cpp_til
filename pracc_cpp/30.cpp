/*基底クラスへのポインタ*/
#include<iostream>

class Number{
    protected: //派生クラスからも扱えるように
        int num;
    public:
        Number(){std::cout << "default num constructor" << std::endl;}
        Number(int in) : num(in){std::cout << "arg 1 num constructor" << std::endl;}

        void set(int in){num = in;}
        int get(){return num;}
        void show(){std::cout << "num:" << num << std::endl;} //show()の定義
};

class Student : public Number{
    private:
        int grade;
    public:
        Student(){std::cout << "default student constructor" << std::endl;}
        Student(int in) : grade(in){std::cout << "arg 1 student constructor" << std::endl;}
        Student(int in1, int in2) : Number(in2), grade(in1){
            std::cout << "arg 2 student constructor" << std::endl;
        } //基本クラスからコンストラクタの呼び出し

        void set(int in){grade = in;}
        int get(){return grade;}
        void show(){
            std::cout << "num:" << num << std::endl;
            std::cout << "grade:" << grade << std::endl;
        } //show()のオーバーライド
};

int main(){
    
    Student obj(2, 317062);
    Number *ptrclass = &obj; //基本クラスへのポインタに派生クラスのポインタを代入できる

    ptrclass->show(); //Number::show()が呼ばれる
    
    return 0;
}
