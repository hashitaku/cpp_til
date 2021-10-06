#include<iostream>

#define FMT_HEADER_ONLY 1
#include<fmt/format.h>

int main(){

    for(size_t i = 0; i < 100000000; i++){
        std::cout << fmt::format("{}", i);
        fmt::format_to(std::ostream_iterator<char>(std::cout), "{}", i);    
        // fmt::print("{}", i);
    }

    return 0;
}
