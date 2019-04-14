#include <iostream>

// using namespace std;

int main(void){
    int num = 20;
    
    std::cout<<"Hello World! ";
    std::cout<<"Hello World!\n";
    std::cout<<"Hello World!"<<std::endl;
    // cout<<"Hello World!"<<endl;
    std::cout<<"Hello "<<"World!"<<std::endl;
    
    std::cout<<num<<' '<<'A';
    std::cout<<' '<<3.14<<std::endl;
    std::cout<<num<<' '<<"changed....";
    // system("pause");
    return 0;
}