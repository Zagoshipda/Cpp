#include <iostream>
using namespace std;
#define endl '\n'

class Point{
    private: 
        int xpos, ypos;
    public:
        Point(int x=0, int y=0): xpos(x), ypos(y){

        }
        void showPosition(){
            cout << "[" << xpos << ", " << ypos << ']' << endl;
        }
        Point operator+(const Point &ref){
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main(void){
    Point pos1(1,2);
    Point pos2(3,4);
    Point pos3 = pos1+pos2;

    pos1.showPosition();
    pos2.showPosition();
    pos3.showPosition();

    return 0;
}