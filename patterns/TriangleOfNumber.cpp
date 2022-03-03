#include <iostream>
using namespace std;

int main() {
    int numOfRows;
    cout << "enter the number of row you want to print" << endl;
    cin >> numOfRows;
    int i =1;
    while (i<= numOfRows)
    {
        int j = 1;
        while (j<=numOfRows-i){
            cout << " ";
            j++;
        }
        j = 1;
        int k = i;
        while (j<=i)
        {
            cout << k;
            k++;
            j++;
        }
        j = k-2;
        while (j>=i){
            cout << j;
            j--;
        }
        cout << endl;
        i++;
        

    }
    
    
}
