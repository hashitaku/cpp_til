/*構造化束縛をラムダキャプチャへ */
#include<iostream>
#include<tuple>

int main(){
    
    auto [a, b] = std::make_tuple(1, 'a');

    auto f = [&a = a](){ return a; }; //ラムダ初期化参照キャプチャ

    a = 2;

    std::cout << f() << std::endl;
    
    return 0;
}
