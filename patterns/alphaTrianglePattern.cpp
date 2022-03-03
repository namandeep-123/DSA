/*
A
AB
ABC
ABCD

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
        while (j <= i ){
            cout << char(alpha + j - 1);
            j++;

        }
        cout << endl;
        i++;
        
    }
}