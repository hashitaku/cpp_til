/*STL List*/
#include<iostream>
#include<list>

int main(){
    
    std::list<int> a = {1, 2, 3};

    auto it = a.begin();

    std::cout << *it << std::endl;
    // std::cout << *(it + 1) << std::endl; 
    std::cout << *(++it) << std::endl;
    
    return 0;
}
