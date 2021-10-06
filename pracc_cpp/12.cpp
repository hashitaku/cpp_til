/*cend() と find()*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int main(){

    vector<int> v = {1,2,3,4,5};

    printf("%p\n%p\n",v.end(),v.cend());//cendはconst endの意味

    return 0;
}
