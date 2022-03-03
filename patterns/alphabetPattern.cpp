/*
ABCD
BCDE
CDEF
DEFG

*/
#include <iostream>
using namespace std;

int main() {
    int numOfRows;
    cout << "enter the number of row you want to print" << endl;
    cin >> numOfRows;
    int i = 1;
    while (i<=numOfRows){
        int j = 1;
        char alpha = 'A';
        int k = i;
        while (j <= numOfRows ){
            cout << char(alpha + k - 1);
            k++;
            j++;

        }
        cout << endl;
        i++;
        
    }
}