#include <iostream>
using namespace std;
#define endl '\n'

template <typename T>
T add(T n1, T n2){
    return n1 + n2;
}

int add(int n1, int n2){
    cout << "add int" << ' ';
    return n1 + n2;
}
double add(double n1, double n2){
    cout << "add double" << ' ';
    return n1 + n2;
}

int main(void){
    
    cout << add(1, 2) << endl;              //add int 3
    cout << add(1.1, 2.2) << endl;          //add double 3.3
    
    // template function/ generated function
    cout << add<int>(1, 2) << endl;         //3
    cout << add<double>(1.1, 2.2) << endl;  //3.3

    return 0;
}