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
        // 객체 배열을 생성하기 위해서는 default constructor가 반드시 필요. 생략할 시 error: no default constructor exists for class "PermanentWorker"
        PermanentWorker(){

        }
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

// action 중심적 class, control/handler class
class EmployeeHandler{
    private:
        // PermanentWorker * empList[50];
        PermanentWorker empList2[50];
        int empNum;
    public:
        //constructor 
        EmployeeHandler(): empNum(0){

        }
        //신규직원등록
            // void AddEmployee(PermanentWorker* emp){
            //     empList[empNum++]=emp;
            // }
        void AddEmployee(PermanentWorker emp2){
            empList2[empNum++]=emp2;
        }
        //전체 직원,급여 정보 출력
        void ShowAllEmployeeInfo2() const{
            for(int i=0; i<empNum; i++){
                cout << "--- employee #" << i+1 << endl;
                empList2[i].ShowWorkerInfo();   //empList2[i] 는 포인터가 아닌 객체 변수 그 자체이므로 -> 가 아닌 . 을 사용해서 멤버함수에 접근한다
            }
        }
        //급여 합계 정보 출력
        void ShowTotalSalary2() const{
            int sum =0;
            for(int i=0; i<empNum; i++){
                sum+=empList2[i].GetPay();
            }
            cout << "salary sum: " << sum << endl;
        }
        //destructor, 객체를 동적 생성하지 않았으므로 delete 필요없음
        ~EmployeeHandler(){
            
        }
};

int main(void){

    //직원 관리를 목적으로 설계된 control class 객체생성
    EmployeeHandler handler;

    //직원 등록 
    PermanentWorker worker1("KIM2", 1000);
    PermanentWorker worker2("Lee2", 1500);
    PermanentWorker worker3("Jun2", 2000);
    handler.AddEmployee(worker1);
    handler.AddEmployee(worker2);
    handler.AddEmployee(worker3);

    handler.ShowAllEmployeeInfo2();  //이번 달 지급 급여 정보
    handler.ShowTotalSalary2();      //이번 달 지불 급여 총합

    return 0;
}