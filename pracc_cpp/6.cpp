/*変数のサイズ*/
#include<iostream>

int main(){

    std::cout << "char:" << sizeof(char) << std::endl;
    std::cout << "int:" << sizeof(int) << std::endl;
    std::cout << "long int:" << sizeof(long int) << std::endl;
    std::cout << "long long int:" << sizeof(long long int) << std::endl;
    std::cout << "double:" << sizeof(double) << std::endl;
    std::cout << "__int8_t:" << sizeof(__int8_t) <<std::endl;
    std::cout << "__int16_t:" << sizeof(__int16_t) << std::endl;
    std::cout << "__int32_t:" << sizeof(__int32_t) << std::endl;
    std::cout << "__int64_t:" << sizeof(__int64_t) << std::endl;

    return 0;
}
