// 유도 클래스 객체의 소멸과정 

// 유도 클래스의 객체가 소멸될 때에는, 유도 클래스의 소멸자가 실행되고 난 후 기초 클래스의 소멸자가 실행된다
// 스택에 생성된 객체의 소멸순서는 생성 순서와 반대 : 기초 클래스 생성자 -> 유도 클래스 생성자 -> 유도 클래스 소멸자 -> 기초 클래스 소멸자


#include <iostream>
using namespace std;
#define endl '\n'

class Base{
    private:
        int baseNum;
    public:
        Base(int n): baseNum(n){
            cout << "Base(n): " << baseNum << endl;
        }
        ~Base(){
            cout << "~Base(): " << baseNum << endl;
        }
};

class Derived : public Base{
    private:
        int derivNum;
    public:
        Derived(int n): Base(n), derivNum(n){
            cout << "Derived(n): " << derivNum << endl;
        }
        ~Derived(){
            cout << "~Derived(): " << derivNum << endl;
        }
};

int main(void){

    Derived dr1(10);
    Derived dr2(20);

    /* output : 객체 dr1 생성 -> 객체 dr2 생성 -> 객체 dr2 소멸 -> 객체 dr1 소멸 
    Base(n): 10
    Derived(n): 10
    Base(n): 20
    Derived(n): 20
    ~Derived(): 20
    ~Base(): 20
    ~Derived(): 10
    ~Base(): 10
    */

    return 0;
}