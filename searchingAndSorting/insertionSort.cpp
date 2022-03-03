#include <iostream>
using namespace std;


void insertionSort(int arr[], int n){
    for (int i = 1; i<n; i++){
        int currentValue = arr[i];
        int j;
        for( j =i-1;j >= 0;j--){
            if(currentValue < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;

            }
        }
            arr[j+1] = currentValue;


    }
}


int main(){
    int arr[] = {5, 10, 2, 7, 4};
    insertionSort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}