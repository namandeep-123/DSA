#include <iostream>
using namespace std;

int isBinary(int arr[], int n, int item){
    int i =0,e = n-1;
    while ( i <= e)
    {
        int m = (i + e) / 2;
        if (arr[m] == item){
            cout << m;
            return 0;
        }
        else if (arr[m] < item){
            i = m +1;
        }
        else{
            e = m -1;
        }
        
    }
    cout << "Not Found";
    
}


int main(){
    int arr[] = {2, 4, 8, 20, 50 ,60};
    int item;
    cout << "Enter item to be Search for:  ";
    cin >> item;
    isBinary(arr,6,item);
}