/*静的メンバ*/
#include<iostream>

class Num{
    private:
        int num;
        static unsigned int cnt;
    public:
        Num() : num(0){cnt++;}
        Num(int in) : num(in){cnt++;}
        unsigned int cntclass(){return cnt;}
        int get(){return num;}
};

unsigned int Num::cnt = 0;

int main(){
    
    Num a;
    Num b;

    std::cout << a.cntclass() << std::endl;
    
    return 0;
}
