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
        First& operator=(const First& ref){
            cout << "First& operator" << endl;
            num1 = ref.num1;
            num2 = ref.num2;
            return *this;
        }
};

class Second : public First{
    private:
        int num3, num4;
    public:
        Second(int n1, int n2, int n3, int n4): First(n1, n2), num3(n3), num4(n4){

        }
        void showData(){
            First::showData();
            cout << num3 << ", " << num4 << endl;
        } 
        // Second& operator=(const Second& ref){
        //     cout << "Second& operator" << endl;
        //     num3 = ref.num3;
        //     num4 = ref.num4;
        //     return *this;
        // }
};

int main(void){
    Second s1(1,2,3,4);
    Second s2(0,0,0,0);
    
    s1.showData();  //1, 2
    s2.showData();  //3, 4

    s2 = s1;
    
    s1.showData();  // 주석 안하면 0, 0 주석하면 1, 2
    s2.showData();  //3, 4

    return 0;
}