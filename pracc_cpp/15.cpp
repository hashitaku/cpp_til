/*列挙型enum*/
#include<iostream>

using namespace std;

int main(){

    enum My_Type {
        hoge = 640, 
        bar = 640, 
        as = 100,
    };

    My_Type tmp = hoge;

    cout << hoge << endl;

    typedef enum {e1, e2, e3} My_Type_Switch;//switchに使うと便利...?

    My_Type_Switch x = e1;//My_Type_Switch型変数xにe1を代入

    switch(x){
        case e1: std::cout << "e1" << '\n'; break;
        case e2: std::cout << "e2" << '\n'; break;
        case e3: std::cout << "e3" << '\n'; break;
    }

    return 0;
}
