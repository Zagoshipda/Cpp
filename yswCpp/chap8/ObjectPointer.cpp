//객체 포인터 변수 : 객체의 주소 값을 저장하는 포인터 변수 
//객체 포인터는 해당 객체(base class) 뿐만이 아닌, 해당 객체를 상속하는 모든 유도 클래스(derived class)의 객체들 또한 가리킬 수 있음

#include <iostream>
using namespace std;
#define endl '\n'

class Person{
    public:
        void Sleep(){
            cout << "Sleep" << endl;
        }
};

class Student : public Person{
    public: 
        void Study(){
            cout << "Study" << endl;
        }
};

class PartTimeStudent : public Student{
    public:
        void Work(){
            cout << "Work" << endl;
        }
};

int main(void){
    Person * ptr0 = new Person();
    Person * ptr1 = new Student();
    Person * ptr2 = new PartTimeStudent;

    Student * ptr3 = new Student();
    Student * ptr4 = new PartTimeStudent();
    PartTimeStudent * ptr5 = new PartTimeStudent();

    ptr0 -> Sleep();
    // ptr0 -> Study();    //error: 'class Person' has no member named 'Study'
    ptr1 -> Sleep();
    // ptr1 -> Study();    //error: 'class Person' has no member named 'Study'
    ptr2 -> Sleep();
    // ptr2 -> Study();    //error: 'class Person' has no member named 'Study'
    // ptr2 -> Work();     //error: 'class Person' has no member named 'Work'
    
    cout << endl;
    ptr3 -> Sleep();
    ptr3 -> Study();
    
    ptr4 -> Sleep();
    ptr4 -> Study();
    // ptr4 -> Work();     //error: 'class Student' has no member named 'Work'

    cout << endl;
    ptr5 -> Sleep();
    ptr5 -> Study();
    ptr5 -> Work();


    return 0;
}