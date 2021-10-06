/*OpenMP*/
#include<iostream>
#include<omp.h>

int main(){
    
    std::cout << omp_get_max_threads() << std::endl;

    size_t num = 0;

#pragma omp parallel for
    for(size_t i = 0; i < 10; i++){
#pragma omp atomic
        num += 1;
        printf("\n");
    }

    std::cout << num << std::endl;
    
    return 0;
}
