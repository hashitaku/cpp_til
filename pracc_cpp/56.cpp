/*テンプレートテンプレートパラメータ*/
#include <iostream>
#include <vector>
#include <list>

template<template<typename T, typename U = std::allocator<T>> typename Container>
struct Hoge{
    using value_type = Container<int>;
    Container<int> con;
};

/*
template<typename Container>
struct Huga{
    using value_type = Container;
    Container con;
};
*/

int main(){
    
    Hoge<std::vector> a;
    // Huga<std::vector<int>> b;

    return 0;
}
