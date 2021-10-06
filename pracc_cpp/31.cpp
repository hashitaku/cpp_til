/*仮想関数*/
#include<iostream>

class Number{
    protected: //派生クラスからも扱えるように
        int num;
    public:
        Number(){std::cout << "default num constructor" << std::endl;}
        Number(int in) : num(in){std::cout << "arg 1 num constructor" << std::endl;}

        void set(int in){num = in;}
        int get(){return num;}
        virtual void show(){std::cout << "num:" << num << std::endl;} //仮想関数show()の定義
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
        void show()override{ //明示的なオーバーライド
            std::cout << "num:" << num << std::endl;
            std::cout << "grade:" << grade << std::endl;
        } //show()のオーバーライド
};

int main(){
    
    Student obj(2, 317062);
    Number *ptr_class = &obj; //基本クラスへのポインタに派生クラスのポインタを代入できる

    ptr_class->show(); //virtualをつけなければNumber::show()が呼ばれる ここではStudent::show()
    
    return 0;
}
