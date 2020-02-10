#include <iostream>
using namespace std;

int main(void){

    int arr[3] = {1, 2, 3};
    int (&ref)[3] = arr;
    cout << ref[0] << ref[1] << ref[2] << endl;
    ref[0] = 9;
    cout << ref[0] << ref[1] << ref[2] << endl;
    cout << ref << ' ' << ref+1 << ' ' << ref+2 << ' ' << endl;
    cout << *ref << ' ' << *(ref+1) << ' ' << *(ref+2) << ' ' << endl;
    
    // in 2 dimensional array, *(*(array+i)+j) == array[i][j]
    // think of it as an array of arrays
    cout << "------------ 2 dimensional" << endl;
    int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    cout << *(*(arr2)) << ' ' << *(arr2) << ' ' << arr2 << endl;
    cout << *(*(arr2)+1) << ' ' << *(arr2)+1 << ' ' << arr2 << endl;
    cout << *(*(arr2+1)) << ' ' << *(arr2+1) << ' ' << arr2+1 << endl;
    cout << typeid(*(*(arr2)+1)).name() << ' ' << typeid(*(arr2)+1).name() << ' ' << typeid(arr2).name() << endl;   // i Pi A3_A2_i

    int (&ref2)[3][2] = arr2;
    cout << typeid(*(*(ref2)+1)).name() << ' ' << typeid(*(ref2)+1).name() << ' ' << typeid(ref2).name() << endl;   // i Pi A3_A2_i

    for(int i=0; i<3; ++i){
        for(int j=0; j<2; ++j){
            cout << ref2[i][j] << ' ' << &ref2[i][j] << ' ';
        }
        cout << endl;
    }

    // address increases by # of cols
    for(int i=0; i<3; ++i){
        for(int j=0; j<2; ++j){
            cout << *(ref2 + i + j) << ' ' << **(ref2 + i + j) << ' ' << *(*(arr2+i)+j) << ' ';
        }
        cout << endl;
    }
    cout << **(ref2) << ' ' << **(ref2+1) << ' ' << **(ref2+2) << ' ' << **(ref2+3) << ' ' << **(ref2+4) << ' ' << **(ref2+5) << ' ' << **(ref2+6) << endl;

    return 0;
}
