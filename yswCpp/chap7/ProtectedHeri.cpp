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

class None : Base{

};

int main(void){
    Public pub;
    Protected pro;
    
    cout << pub.n2 << endl; //error: 'int Base::n2' is protected within this context
    cout << pub.n3 << endl;
    // cout << pro.n3 << endl; //error: 'int Base::n3' is inaccessible


    return 0;
}