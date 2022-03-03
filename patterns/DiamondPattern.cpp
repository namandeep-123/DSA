#include <iostream>
using namespace std;

int main(){
    int numOfRows;
    cout <<"Enter the rows you want to enter" << endl;
    cin >> numOfRows;
    int n1 = (numOfRows+1)/2;
    int n2 = numOfRows/2;
    int i = 1;
    while (i<=n1)
    {
        int j = 1;
        while (j<=n1-i){
            cout << " ";
            j++;
        }
        j = 1;
        while (j<=i){
            cout << "*";
            j++;
        }
        j = i - 1;
        while (j >= 1)
        {
            cout<< "*";
            j--;
        }
        i = 3;
        j = 1;
        while (j <= n2 -i+1){
            cout << " ";
            j++;
        }
        j = 1;
        while (j<=i){
            cout << "*";
            j++;
        }
        j = i - 1;
        while (j >= 1)
        {
            cout<< "*";
            j--;
        }

        
    }
    
}