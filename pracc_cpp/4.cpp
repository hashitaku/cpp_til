/*関数オーバーロード*/
#include<iostream>

using namespace std;

int max(int x, int y);
double max(double x, double y);

int main(){

    int a,b;

    cin >> a >> b;

    cout << max(a, b) << endl; //引数にあった型の関数が呼び出される

    return 0;
}

int max(int x, int y){
    if(x >= y){
        return x;
    }else{
        return y;
    }
}

double max(double x, double y){
    if(x >= y){
        return x;
    }else{
        return y;
    }
}
