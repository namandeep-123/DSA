#include <iostream>
using namespace std;

int main(){
    int n,i=1;
    cout << "enter The pattern length";
    cin >> n;
    while (i <= n){
        int j = 1;
        while (j <= i)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
        
    }
}