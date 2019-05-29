// 유도 클래스의 객체 생성과정 알아보기 - 기초 클래스의 생성자 호출 + 유도 클래스의 생성자 호출

// 기본원칙: 클래스의 멤버는 해당 클래스의 생성자를 통해서 초기화해야 함, 이 원칙은 유도 클래스의 객체를 생성하는 과정에서도 지켜야 하며, 따라서 기초 클래스의 생성자를 호출하고 기초 클래스의 멤버변수까지를 초기화하는 과정을 수행해야 하는 것 

// 1. 유도 클래스의 객체 생성 과정에서 기초 클래스의 생성자는 항상 호출된다 
// 2. 유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면 기초 클래스의 void 생성자가 호출된다 

#include <iostream>
using namespace std;
#define endl '\n'

class Base{
    private:
        int baseNum;
    public:
        Base(): baseNum(-1){
            cout << "Base()" << endl;
        }
        Base(int n): baseNum(n){
            cout << "Base(n)" << endl;
            // ShowBaseData();
        }
        void ShowBaseData(){
            cout << "baseNum: " << baseNum << endl;
        }
};

class Derived : public Base{
    private:
        int derivNum;
    public:
        Derived(): derivNum(-1){
            cout << "Derived()" << endl;
        }
        // Case#1: 기초 클래스의 생성자 호출을 명시하지 않음 -> 기초 클래스의 void 생성자 Base() 호출 
        // Derived(int n): derivNum(n){
        //     cout << "Derived(n)" << endl;
        // }
        // Case#2: 기초 클래스의 생성자 호출을 명시 -> 기초 클래스의 Base(int n) 생성자 호출
        Derived(int n): Base(1), derivNum(n){
            cout << "Derived(n)" << endl;
        }
        Derived(int n, int m): Base(n), derivNum(m){
            cout << "Derived(n, m)" << endl;
        }
        void ShowDerivData(){
            ShowBaseData();
            cout << "derivNum: " << derivNum << endl;
        }
};

int main(void){

    cout << "case 1..." << endl;
    Derived dr1;
    dr1.ShowDerivData();
    cout << endl;

    cout << "case 2..." << endl;
    Derived dr2(12);
    dr2.ShowDerivData();
    cout << endl;

    cout << "case 3..." << endl;
    Derived dr3(15, 16);
    dr3.ShowDerivData();


    // case 1...
    // Base()
    // Derived()
    // baseNum: -1
    // derivNum: -1

    // case 2...
    // Base()
    // Derived(n)
    // baseNum: 1 / -1
    // derivNum: 12

    // case 3...
    // Base(n)
    // Derived(n, m)
    // baseNum: 15
    // derivNum: 16

    return 0;
}