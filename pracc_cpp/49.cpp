/*テンプレートパラメータに関数ポインタを渡す*/

using ft = double (*)(double);

constexpr double func(double a){
    return a * 2.0;
}

template<ft F>
constexpr double g(double a){
    return F(a);
}

int main(){
    
    constexpr auto a = g<func>(1.0);
    
    return 0;
}
