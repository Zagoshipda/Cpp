#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

class Person{
    private:
        char* name;
        int age;
    public:
        //Person(char* myname, int myage) 으로 할 경우 warning : C++ forbids converting a <string constant> to 'char*'
        //즉, string은 값을 바꿀 수 없으므로 아래와 같이 const를 붙여주어야 warning msg 가 나오지 않는다. 참고로 const의 위치에 따른 상수화의 차이에 대해 주의하자. const 가 앞에 나오면 가리키는 변수의 상수화, char* const 이면 포인터 변수의 상수화(가라키는 대상을 변경할 수 없음)
        Person(const char* myname, int myage){
            int len = strlen(myname)+1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        void ShowPersonInfo() const{
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
        }
        ~Person(){
            delete[] name;
            cout << "called destructor...!" << endl;
        }
};  //class 마지막에 ; 달기 

int main(void){

    Person man1("Lee dong woo", 29);
    Person man2("Jang dong gun", 30);

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
