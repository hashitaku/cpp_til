/*非型テンプレートとテンプレートメタ*/
#include<iostream>

template<int N>
struct f{
    static const long long int value = N * f<N - 1>::value;
};

template<>
struct f<0>{
    static const long long int value = 1;
};

int main(){
    
    std::cout << f<10>::value << std::endl;
    
    return 0;
}
