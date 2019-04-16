#include <iostream>
using namespace std;
#define endl '\n'

class SoSimple{
private: 
    int num;
public:
    SoSimple(int n) : num(n){
        cout << "New object: " << this << endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num){
        cout << "New Copy obj: " << this << endl;
    }
    ~SoSimple(){
        cout << "Destroy obj: " << this << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob){
    cout << "   address: " << &ob << endl;
    return ob;
}

int main(void){
    SoSimple obj(10); cout << endl;

    cout << "---function start" << endl;
    SimpleFuncObj(obj);
    cout << "---function end" << endl << endl;

    cout << "---function start" << endl;
    SoSimple ref = SimpleFuncObj(obj);
    cout << "---function end" << endl << endl;

    cout << "func return: " << &ref << endl << endl;

    return 0;
}