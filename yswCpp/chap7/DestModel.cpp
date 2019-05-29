// 유도 클래스 객체의 소멸과정 

// 기본원칙: 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제시켜야 함
// 유도 클래스의 생성자, 소멸자 정의 모델 -> 각 클래스마다 생성자에서 할당한 메모리 공간은 소멸자에서 해제하도록 책임을 진다


#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

class Person{
    private:
        char * name;
    public:
        //283p. UnivStudentInheri.cpp Person() 생성자와 비교: Person클래스의 생성자에서는 argument로 받은 myname을 바로 strcpy하고 있다. 차이가 발생하는 이유는? -> 해당하는 클래스에서는 name변수의 크기를 이미 고정된 값으로 선언해주었기 때문(char name[50]) 이에 반면 지금 클래스에서는 name변수를 int 포인터 변수로 선언했으므로 그 크기를 지정하지 않은 상태이다. 따라서 아래 생성자에서는 strcpy가 적당하게 일어날 수 있도록 argument로 들어온 myname의 크기+1(문자열을 나타내기 위해서는 마지막에 null문자를 삽입해야 하므로 크기를 1 더 크게 잡는다)만큼의 메모리 공간을 new 키워드로 동적 할당한 뒤 클래스의 멤버변수인 char 포인터 변수 name에 assign하고 있다. 그리고 그 후 strcpy를 통해 myname의 값을 name으로 복사하여 값의 대입을 완료한다. 
        // constructor
        Person(const char* myname){
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
            cout << "Person constructor " << name << endl;
        }
        //destructor: base class에서 할당한 메모리 공간은 base class에서 해제한다 
        ~Person(){
            cout << "Person destructor " << name << endl;   
            delete[] name;
            // cout << "Person destructor " << name << endl;    // name 변수를 먼저 delete 한 후에 출력하면 정상적으로 출력되지 않음 
        }
        void PrintName() const{
            cout << "name: " << name << endl;
        }
};

class UnivStudent : public Person{
    private:
        char * major;
    public:
        //base class의 생성자에서와 마찬가지로 우선 argument로 들어온 myjaor+1 만큼의 크기를 동적할당하여 멤버변수 major의 크기를 설정해준 뒤, strcpy를 통해 mymajor의 값을 major으로 복사한다
        //constructor
        UnivStudent(const char* myname, const char* mymajor): Person(myname){
            major = new char[strlen(mymajor)+1];
            strcpy(major, mymajor);
            cout << "UnivStudent constructor " << major << endl;
        }
        //destructor: derived class에서 할당한 메모리 공간은 derived class에서 해제한다 
        ~UnivStudent(){
            cout << "UnivStudent destructor " << major << endl;
            delete[] major;
        }
        void PrintData(){
            PrintName();
            cout << "major: " << major << endl;
        }
};


int main(void){
    UnivStudent st1("Lee", "mathematics");
    st1.PrintData();
    cout << endl;

    UnivStudent st2("Yoo", "Art");
    st2.PrintData();
    cout << endl;

    // output ----- st1 객체 생성 (base class constructor -> derived class constructor) -> st2 객체 생성 -> st2 객체 소멸 -> st1 객체 소멸 (derived class destructor -> base class destructor)
    /*
    Person constructor Lee
    UnivStudent constructor mathematics 
    name: Lee
    major: mathematics

    Person constructor Yoo
    UnivStudent constructor Art
    name: Yoo
    major: Art

    UnivStudent destructor Art
    Person destructor Yoo
    UnivStudent destructor mathematics 
    Person destructor Lee 
    */

    return 0;
}
