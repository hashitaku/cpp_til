/*push_back(言語機能)*/
#include<iostream>
#include<vector>

int main(){

    std::vector<int> v;

    for(int i = 0; i < 5; i++){
        int t;
        std::cin >> t;
        v.push_back(t);
    }

    for(int i = 0; i < 5; i++){
        std::cout << v[i] << std::endl;
    }

    return 0;
}
