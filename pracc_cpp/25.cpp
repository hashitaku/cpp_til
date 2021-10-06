/*ファイル入出力*/
#include<iostream>
#include<fstream>

int main(){

    std::fstream file("./sample");

    if(file.is_open() == false){
        std::cerr << "file open error" << std::endl;
        return EXIT_FAILURE;
    }

    

    file.close();

    return 0;
}
