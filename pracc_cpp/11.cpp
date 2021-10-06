/*find cend*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    std::vector<int> v = {1,2,3,4,5};
    int a;

    auto x = find(v.begin(), v.end(), 5);
    //auto は std::vector<int>::const_iterator型

    if(x != v.cend()){
        std::cout << *x << std::endl;
    }else{
        std::cout << "なし" << std::endl;
    }

    return 0;
}
