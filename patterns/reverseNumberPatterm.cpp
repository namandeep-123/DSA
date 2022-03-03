/*
pattern
1
21
321
4321
*/

#include <iostream>
using namespace std;

int main() {
    int numOfRows;
    cout << "enter the number of row you want to print" << endl;
    cin >> numOfRows;
    int i =1;
    while (i <= numOfRows)
    {
        int j = i;
        while (j >= 1){
            cout << j;
            j--;
        }
        cout << endl;
        i++;


    }
    
}

