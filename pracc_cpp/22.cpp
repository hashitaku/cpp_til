/*右辺値参照*/
#include<iostream>

int main(){
    
    const int &rrvalue = 20;
    int &&rrvalue2 = 30;

    std::cout << rrvalue << std::endl;
    std::cout << rrvalue2 << std::endl;

    //rrvalue = 40; //エラー
    rrvalue2 = 50;

    std::cout << rrvalue2 << std::endl;
    
    return 0;
}
