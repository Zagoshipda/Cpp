#include <iostream>
using namespace std;
#define endl '\n'


class SelfRef{
private:
    int num;
public:
    SelfRef(int n): num(n){
        cout << "object initialize" << endl;
    }
    SelfRef& Adder(int n){
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNum(){
        cout << num <<endl;
        return *this;
    }
    SelfRef* returnthis(){
        return this;
    }
    SelfRef returnthisref(){
        return *this;
    }
};

int main(void){

    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNum();   //5
    ref.ShowTwoNum();   //5

    ref.Adder(1).ShowTwoNum().Adder(2).ShowTwoNum();    // 6 8 

    SelfRef *ptr = obj.returnthis();
    cout << ptr << endl;    //address
    SelfRef obj2 = obj.returnthisref();
    cout << (&obj2) << endl;    //address
    obj2.ShowTwoNum();  //8
    cout << sizeof(obj) << ' ' << sizeof(obj2) << endl; //4 4


    return 0;
}