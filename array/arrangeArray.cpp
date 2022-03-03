#include <iostream>
using namespace std;


void arrangeArray(int arr[], int n){
    for(int i = 0; i< n; i+=2){
        cout <<arr[i] << " ";
    }
    int i;
    if (n % 2 == 0){
        i = n -1;
    }
    else{
        i = n-2;
    }
    for(; i >= 1; i-=2){
        cout <<arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Array Length :"<< " ";
    cin >> n;
    int arr[10];
    for (int i = 0 ; i<n; i++){
        cin >> arr[i];
    }
    arrangeArray(arr, n);
}