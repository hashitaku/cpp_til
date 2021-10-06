/*クラスの定義*/
#include<iostream>
#include<vector>
#include<string>
#include<array>

using namespace std;

class SuwaRikaHuman{
    private:
        unsigned int height;
        unsigned int weight;
        unsigned int age;
        char sex;
        string department;
        string name;
    public:
        creat();
        void SetHeight(unsigned int);
        void SetWeight(unsigned int);
        void SetAge(unsigned int);
        void SetSex(char);
        void SetDepartment(const char *);
        void SetName(const char *);
}

int main(){



    return 0;
}

SuwaRikaHuman::creat(){
    cout << "succcess creat object" << endl;
    height = 0;
    weight = 0;
    age = 0;
}

void SuwaRikaHuman::SetHeight(unsigned int n){
    if(num <= 0){
        cout << "正しい値を入力してください" << endl;
    }else{
        height = num;
        cout << "身長をセットしました" << endl;
    }
}

void SuwaRikaHuman::SetWeight(unsigned int n){
    if(num <= 0){
        coud << "正しい値を入力してください" << endl;
    }else{
        weight = num;
        cout << "体重をセットしました" << endl;
    }
}

void SuwaRikaHuman::SetAge(unsigned int n){
    if(n < 0){
        cout << "正しい値を入力してください" << endl;
    }else{
        age = n;
        cout << "年齢をセットしました" << endl;
    }
}

void SuwaRikaHuman::SetSex(char s){
    if(s == 'm' && s == 'f'){
        sex = s;
        cout << "性別をセットしました" << endl;
    }else{
        cout << "正しい文字を入力してください(m / f)" << endl;
    }
}

void SuwaRikaHuman::SetDepartment(const char *s){
    if(s = "cs" || s == "es" || s == "ms"){
        department =
    }
}
