#include <iostream>
using namespace std;

int Sum(int arr[], int n){
    if (n == 0){
        return 0;
    }
    int smallOutput = Sum(arr+1,n-1);
    int sum = arr[0] + smallOutput;
    return sum;
}

int main(){
    int arr[] = {2,3,4,5,6,7,8};
    cout<<Sum(arr,7);
}