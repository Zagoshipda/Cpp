#include <iostream>
#include <cstring>
using namespace std;

class Simple{
// private:
public:
    int num;
public:
    Simple(int n) : num(n){
        cout << "num = " << num << ", " << "address = " << this << endl;
    }
    void ShowSimpleData(){
        cout << num << endl;
    }
    Simple * GetThisPointer(){
        return this;
    }
}; 

int main(void){
    cout << "start \n" << endl;

    Simple sim1(100);
    Simple * ptr1 = sim1.GetThisPointer();  //sim1 객체의 주소 저장
    cout << ptr1 << ", ";
    ptr1 -> ShowSimpleData();
    (*ptr1).ShowSimpleData();

    Simple sim2(200);
    Simple * ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();
        // cout << (*ptr2) << endl; //error...?
    cout << &(sim2.num) << endl;

    cout << "..lol" << endl; //한글 출력 확인 
    
    return 0;
}