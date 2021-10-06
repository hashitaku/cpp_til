/*キャプチャの寿命*/
#include<iostream>
#include<vector>

auto f(const std::vector<int> &v){
    auto ret = [&v](){ return v[0]; };

    return ret;
}

int main(){
    
    auto a = f({1, 2});

    std::cout << a() << std::endl;
    
    return 0;
}
