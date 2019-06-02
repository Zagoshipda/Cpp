// 상속과 접근 제어 지시자 access specifier - public, protected, private 

#include <iostream>
using namespace std;
#define endl '\n'

class Base{
    private:
        int n1;
    protected:
        int n2;
    public:
        int n3;

        Base(): n1(1), n2(2), n3(3){

        }
};

class Protected : protected Base{

};

class Public : public Base{

};

// https://stackoverflow.com/questions/4796789/default-inheritance-access-specifier
// the default type of the inheritance depends on the inheriting type (B), not on the one that is being inherited (A)

// class A {};
// struct B: /* public */ A {};

// struct A {};
// class B: /* private */ A {};

class None : Base{  // class None : private Base 

};

int main(void){
    Base b;         //n1: private, n2: protected, n3: public 
    Public pub;     //n2: protected, n3: public
    Protected pro;  //n2: protected, n3: protected
    None no;        //n2: private, n3: private
    
    // 1. 우선 클래스 외부에서는 public으로 선언된 변수들에만 접근할 수 있음
    // cout << b.n1 << ' ' << b.n2 << ' ' << endl; //error: 'int Base::n1' is private, 'int Base::n2' is protected
    cout << b.n3 << endl;       //3

    // 2. public으로 상속하는 경우는 private은 접근불가, protected는 protected그대로, public은 public그대로 상속 
    // cout << pub.n1 << endl;  //error: 'int Base::n1' is private
    // cout << pub.n2 << endl;  //error: 'int Base::n2' is protected 
    cout << pub.n3 << endl;     //3
    
    // 3. protected로 상속하는 경우는 private은 접근불가, protected는 protected그대로, public은 protected로 바뀌어서 상속
    // cout << pro.n1 << endl; //error: 'int Base::n1' is private
    // cout << pro.n2 << endl; //error: 'int Base::n2' is protected
    // cout << pro.n3 << endl; //error: 'int Base::n3' is inaccessible
    
    // 3. private으로 상속하는 경우는 private은 접근불가, protected는 private으로 바뀌어서, public은 private으로 바뀌어서 상속
    // cout << no.n1 << endl;  //error: 'int Base::n1' is private
    // cout << no.n2 << endl;  //error: 'int Base::n2' is protected
    // cout << no.n3 << endl;  //error: 'int Base::n3' is inaccessible


    return 0;
}