#include<iostream>
#include<list>

int main(){
    
    std::list<int> l;

    for(size_t i = 0; i < 10; i++){
        l.push_back(i);
    }

    std::cout << l.front() << std::endl;

    
    
    return 0;
}
