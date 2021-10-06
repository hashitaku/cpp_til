/*関数テンプレートの利用*/
#include<iostream>

using namespace std;

template <class T>
T maxt(T x, T y);

int main(){

    int ia,ib;
    double da,db;

    cout << "整数:"; cin >> ia >> ib;
    cout << "実数:"; cin >> da >> db;

    cout << maxt(ia, ib) << endl;
    cout << maxt(da, db) << endl;

    return 0;
}

template <class T>
T maxt(T x, T y){
    if(x >= y){
        return x;
    }else{
        return y;
    }
}
