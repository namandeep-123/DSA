#include <iostream>
using namespace std;


int particion(int a[], int start, int end){
    int pivot = a[start];
    int counter = 0;
    for(int i =start+1;i<=end;i++){
        if(a[i] < pivot){
            counter++;
        }
    }
    int pivotIndex = counter+start;
    a[start] = a[pivotIndex];
    a[pivotIndex] = pivot;
    int i = start;
    int j = end;

    while(i<pivotIndex && j > pivotIndex){
        if(a[i] < pivot){
            i++;
        }
        else if(a[j] > pivot){
            j++;
        }else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }

    return pivotIndex;
 
}

void quick_sort(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int c = particion(input,start,end);
    quick_sort(input,start,c-1);
    quick_sort(input,c+1,end);
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    quick_sort(arr,0,5);
    for(int i = 0;i <6;i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

}