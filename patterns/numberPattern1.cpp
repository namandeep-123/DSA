#include <iostream>
using namespace std;

int main(){
    int n,i=1;
    cout << "enter The pattern length";
    cin >> n;
    int p = 1;
    while (i <= n){
        int j = 1;
        while (j <= i)
        {
            cout << p;
            j++;
            p++;
        }
        cout << endl;
        i++;
        
    }
}