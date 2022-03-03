#include <iostream>
using namespace std;


void merge(int a[], int start, int end, int mid){
    int size = end-start +1;
    int* out = new int[size];
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=end){
        if(a[i] < a[j]){
            out[k] = a[i];
            k++;
            i++;
        }else{
            out[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        out[k] = a[i];
        k++;
        i++;
    }
    while(j<=end){
        out[k] = a[j];
        k++;
        j++;
    }
    int m =0;
    for(int i = start;i<=end;i++){
        a[i] = out[m];
        m++;
    }
    delete  [] out;
}

void merge_sort(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end) /2;
    merge_sort(input,start,mid);
    merge_sort(input,mid+1,end);
    merge(input,start,end,mid);
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    merge_sort(arr,0,5);
    for(int i =0; i<6; i++){
        cout<<arr[i] << " ";
    } 
    cout<<endl;

}