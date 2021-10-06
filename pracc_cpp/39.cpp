/*eigen使ってみた*/
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Eigen>
#include<eigen3/Eigen/Eigenvalues>
#include<eigen3/Eigen/LU>
#include<iostream>
#include<complex>

using cmpd = std::complex<double>;

int main(){
    
    Eigen::MatrixXcd mat(4, 4);

    mat << cmpd(-2.0, 0.0), cmpd(8.0, -3.0), cmpd(4.0, 7.0), cmpd(-3.0, 2.0),
           cmpd(8.0, 3.0), cmpd(4.0, 0.0), cmpd(1.0, -1.0), cmpd(-1.0, -5.0),
           cmpd(4.0, -7.0), cmpd(1.0, 1.0), cmpd(-5.0, 0.0), cmpd(0.0, -6.0),
           cmpd(-3.0, -2.0), cmpd(-1.0, 5.0), cmpd(0.0, 6.0), cmpd(1.0, 0.0);

    std::cout << mat << std::endl;
    std::cout << std::endl;

    std::cout << mat.eigenvalues() << std::endl;
    std::cout << std::endl;

    Eigen::Matrix2d mat2(2, 2);

    mat2 << 3, -2,
            4, -5;
    
    auto mat3 = mat2.lu();

    std::cout << mat3.matrixLU() << std::endl;
    
    return 0;
}
