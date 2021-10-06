/*可変長テンプレート*/
#include<iostream>

void print(){
    std::cout << std::endl;
}

template<typename TypeHead, typename... TypeBody>
void print(TypeHead head, TypeBody... body){
    std::cout << head << "(" << sizeof...(body) << ")";
    if(sizeof...(body) > 0) std::cout << " ";
    print(body...);
}

int main(){

    int a = 292;
    double b = 372.2;
    
    print(2, 3.5, "dwhaud", 'w', a, b);
    
    return 0;
}
