#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

class Person{
    private:
        int age;
        char name[50];
    public:
        Person(int myage, const char* myname): age(myage){
            strcpy(name, myname);
            // name = myname;  //expression must be a modifiable lvalue
        }
        void PrintName() const{
            cout << "name: " << name << endl;
        }
        void PrintAge() const{
            cout << "age: " << age << endl;
        }
};

class UnivStudent : public Person{
    private:
        char major[50];
    public:
        //constructor, 유도 클래스에서의 초기화 작업은 기초 클래스인 Person class의 멤버까지 초기화의 범위에 포함하며, 이 과정은 기초 클래스의 생성자를 <member initializer를 이용하여 호출>하는 것으로 보다 간단하게 수행할 수 있다.
        UnivStudent(const char* myname, int myage, const char* mymajor): Person(myage, myname){
            strcpy(major, mymajor);
        }
        void PrintData() const{
            PrintName();
            PrintAge();
            cout << "major: " << major << endl;
        }
};

int main(void){
    UnivStudent ustd1("Lee", 22, "CSE");
    UnivStudent ustd2("Park", 24, "Mathematics");

    ustd1.PrintData();
    ustd2.PrintData();

    return 0;
}