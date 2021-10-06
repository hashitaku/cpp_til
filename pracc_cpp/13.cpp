/*typeid 型を調べる*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>

using namespace std;

int main(){

    std::vector<int> v = {1,2,3,4,5};
    int a;
    int *b;

    auto x = v.end();
    auto y = v.cend();

    cout << typeid(v).name() << endl;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    return 0;
}
