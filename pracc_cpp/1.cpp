//インクリメント　デクリメントの後置と前値
#include<iostream>

using namespace std;

int main(){

  int a = 0, b = 0;

  b = ++a;
  /*aの値を1増やしてからbに代入する。*/
  
  //b = a++;
  /*bにaの値を代入してから1増やす。*/

  cout << "代入後にインクリメントしたのでbの値は" << b << "です。" << endl;

  return 0;

}
