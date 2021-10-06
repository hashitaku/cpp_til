/*rbegin()とrend()逆イテレーター*/

#include<iostream>
#include<cstdio>
#include<array>
#include<algorithm>

using namespace std;

int main(){

    array<int, 5> v;

    printf("%p %p\n%p %p\n",v.begin(), v.rbegin(), v.end(), v.rend());
    printf("%p\n",&v[0]);

    return 0;
}
