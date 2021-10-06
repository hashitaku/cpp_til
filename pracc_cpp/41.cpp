/*構造化束縛*/
#include<iostream>
#include<tuple>
#include<vector>

int main(){
    
    std::tuple<int, double> t = std::make_tuple(362, 1.6);

    auto [a, b] = t;

    std::cout << a << " " << b << std::endl;

    std::vector<std::tuple<int, double>> vt(5);

    for(auto&& e : vt){
        e = std::make_tuple(1, 2.6);
    }

    for(const auto& [first, second] : vt){ //range based forでも構造化束縛は使える
        std::cout << first << " " << second << std::endl;
    }
    
    
    return 0;
}
