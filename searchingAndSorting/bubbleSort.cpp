#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for (int i =0;i<n-1;i++){
        int temp;
        for(int j = 0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            
            
        }
    }
}



int main(){
    int arr[] = {10, 1, 7, 14, 5,2,54,3};
    bubbleSort(arr,8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    
}