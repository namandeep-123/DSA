#include <iostream>
using namespace std;

void mergeSort(int arr1[], int arr2[], int m, int n){
    int arr3[20];
    int i=0,j=0,k=0;
    while(j<m && k<n){
        if (arr1[j] < arr2[k]){
            arr3[i] = arr1[j];
            j++;
            i++;
        }
        else{
            arr3[i] = arr2[k];
            k++;
            i++;
        }
    }
    while(j < m){
        arr3[i] = arr1[j];
        i++;
        j++;
    }
    while(k < n){
        arr3[i] = arr2[k];
        i++;
        k++;
    }

    for(int i =0; i<8;i++){
        cout << arr3[i] << " ";
    }
}

int main(){
    int arr1[] = {1, 9, 12, 20,25};
    int arr2[] = {2, 8, 15};
    mergeSort(arr1,arr2,5,3);
}