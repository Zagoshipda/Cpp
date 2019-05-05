#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

class Person{
    private:
        char * name;
        int age;
    public:
        Person(const char* myname, int myage){
            int len = strlen(myname)+1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        // copy constructor 복사 생성자 for object man2
        Person(Person& p): age(p.age){
            name = new char[strlen(p.name)+1];
            strcpy(name, p.name);
            cout << "hi im copy constructor" << endl;
        }
        void ShowPersonInfo(){
            cout << "name: " << name << endl;
            cout << "age: " << age << endl;
        }
        ~Person(){
            delete[] name;
            cout << "called destructor...!" << endl;
        }
};

int main(void){

    Person man1("Konan Deep copy", 15);
    Person man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    // 원래 예제의 의도에 따르자면 destructor가 1번 호출되는 것이 맞지만 compiler에 따라 2번 모두 출력될 수도 있으며 현재 g++로는 2번 출력된다
    // called destructor...!
    // called destructor...!

    return 0;
}
