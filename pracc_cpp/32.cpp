/*例外処理*/
#include<iostream>

void f(int);

int main(){
    
    try{
        f(-10);
        f(23);
        f(192);
    }
    catch(...){
        std::cout << "err_str" << std::endl;
    }
    
    return 0;
}

void f(int a){
    if(a < 0){
        throw "input num under 0";
    }else if(a > 100){
        throw "input num over 100";
    }else{
        std::cout << a << std::endl;
    }
}
