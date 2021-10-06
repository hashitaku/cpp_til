/*関数の引数に構造体を渡す(値渡し、ポインタ渡し)*/
#include<iostream>

using namespace std;

typedef struct{
    char name[21];
    char sex;
    int age;
}HUMAN;

void s_out(HUMAN);
void s_ptr_out(HUMAN*);

int main(){

    HUMAN me;
    HUMAN *s_ptr = &me;

    cout << "name->"; cin >> me.name;
    cout << "sex(m/f)->"; cin >> me.sex;
    cout << "age->"; cin >> me.age;

    s_out(me);
    s_ptr_out(s_ptr);
    s_ptr_out(&me);

    return 0;
}

void s_out(HUMAN hoge){
    cout << hoge.name << endl;
    cout << hoge.sex << endl;
    cout << hoge.age << endl;
}

void s_ptr_out(HUMAN *hoge){
    cout << hoge->name << endl;
    cout << hoge->sex << endl;
    cout << hoge->age << endl;
}
