#include <iostream>
using namespace std;

namespace BestComImpl{
    void SimpleFunc(void){
        cout << "BestCom이 정의한 함수" << endl;
    }
}
namespace ProgComImpl{
    void SimpleFunc(void){
        cout << "ProgCom이 정의한 함수" << endl;
    }
}

int main(void){
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}