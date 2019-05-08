#include <iostream>
using namespace std;
#define endl '\n'

class First{
    private:
        int num1, num2;
    public:
        First(int n1=0, int n2=0): num1(n1), num2(n2){
 
        }
        void showData(){
            cout << num1 << ", " << num2 << endl;
        }
        // default 대입 연산자 Copy Assignment Operator 
        // First& operator=(const First& ref){
        //     num1 = ref.num1;
        //     num2 = ref.num2;
        //     return *this;
        // }
};

class Second{
    private:
        int num3, num4;
    public:
        Second(int n3=0, int n4=0): num3(n3), num4(n4){

        }
        void showData(){
            cout << num3 << ", " << num4 << endl;
        } 
        Second& operator=(const Second& ref){
            cout << "Second& operator=()" << endl;
            num3 = ref.num3;
            num4 = ref.num4;
            return *this;
        }
};

int main(void){
    First f1(111, 222);
    First f2;
    Second s1(33, 44);
    Second s2;

    f2 = f1;
    s2 = s1;
    f1.showData();
    s1.showData();
    f2.showData();
    s2.showData();

    First f3, f4;
    Second s3, s4;
    f3 = f4 = f1;
    s3 = s4 = s1;

    f3.showData(), f4.showData();
    s3.showData(), s4.showData();

    return 0;
}