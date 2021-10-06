/*クラスの継承*/
#include<iostream>

class Number{
    private:
        int num;
    public:
        Number(){std::cout << "default num constructor" << std::endl;}
        Number(int in) : num(in){std::cout << "arg 1 num constructor" << std::endl;}

        void setNum(int in){num = in;} //29.cppへ
        int getNum(){return num;} //29.cppへ
};

class Student : public Number{ //public継承
    private:
        int grade;
    public:
        Student(){std::cout << "default student constructor" << std::endl;}
        Student(int in) : grade(in){std::cout << "arg 1 student constructor" << std::endl;}
        Student(int in1, int in2) : Number(in2), grade(in1){
            std::cout << "arg 2 student constructor" << std::endl;
        } //基本クラスからコンストラクタの呼び出し

        void setGrade(int in){grade = in;} //29.cppへ
        int getGrade(){return grade;} //29.cppへ
};

int main(){
    
    Student a(2, 317062);
    
    return 0;
}
