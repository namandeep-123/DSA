#include <iostream>
using namespace std;

int main() {
    int numOfRows;
    cout << "enter the number of row you want to print" << endl;
    cin >> numOfRows;
    int i = 1;
    while (i<=numOfRows){
        int j = 1;
        while(j <= numOfRows){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}