#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'

// data 중심적 class
class PermanentWorker{
    private:
        char name[100];
        int salary;
    public:
        PermanentWorker(const char* name, int money): salary(money){
            strcpy(this->name, name);   //this 는 포인터이므로 *().name 과 같음
        }
        int GetPay() const{
            return salary;
        }
        void ShowWorkerInfo() const{
            cout << "name: " << name << ", salary: " << GetPay() << endl << endl;
        }
};

// action 중심적 class 
class EmployeeHandler{
    private:
        PermanentWorker * empList[50];
        // PermanentWorker empList2[50];
        int empNum;
    public:
        //constructor 
        EmployeeHandler(): empNum(0){

        }
        //신규직원등록
        void AddEmployee(PermanentWorker* emp){
            empList[empNum++]=emp;
        }
            // void AddEmployee(PermanentWorker emp2){
            //     empList2[empNum++]=emp2;
            // }
        //전체 직원,급여 정보 출력
        void ShowAllEmployeeInfo() const{
            for(int i=0; i<empNum; i++){
                cout << "--- employee #" << i+1 << endl;
                empList[i]->ShowWorkerInfo();   //empList[i] 는 객체 포인터이므로 -> 를 이용해서 객체의 멤버함수에 접근할 수 있다. foo->bar() == (*foo).bar()
                (*empList[i]).ShowWorkerInfo(); //arrow operator와 같음, *를 구한 전체에 대해 멤버 . 을 구하는 것이고 .이 *보다 연산자 우선순위를 가지므로 괄호를 쳐주어야 한다.
                // but the . operator has greater precedence than the * operator, so we need to force this with parenthesis: (*pointer).foo, rather than, *pointer.foo. But typing the parenthesis ()'s all the time is hard so C/C++ allows us to use -> as a shortcut which means the same thing.
            }
        }
        //급여 합계 정보 출력
        void ShowTotalSalary() const{
            int sum =0;
            for(int i=0; i<empNum; i++){
                sum+=empList[i]->GetPay();
            }
            cout << "salary sum: " << sum << endl;
        }
        //destructor
        ~EmployeeHandler(){
            // ... ? 동적으로 할당한 부분이 어디 있는지...? -> 아래 main함수에서 객체를 동적으로 생성한 후 add하는 것 확인
            for(int i=0; i<empNum; i++){
                delete empList[i];  
            }
        }
};

int main(void){

    //직원 관리를 목적으로 설계된 control class 객체생성
    EmployeeHandler handler;

    // 직원 등록, 객체 동적 할당 
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    handler.AddEmployee(new PermanentWorker("Jun", 2000));

    handler.ShowAllEmployeeInfo();  //이번 달 지급 급여 정보
    handler.ShowTotalSalary();      //이번 달 지불 급여 총합

    return 0;
}