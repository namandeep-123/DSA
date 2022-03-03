#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(int arr[],int beg,int end){
    int i=beg+1;
    int piv=arr[beg];
    for(int j=beg+1;j<=end;j++){
        if(arr[j]<piv){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[beg],arr[i-1]);
    return i-1;
}

void quicksort(int arr[],int beg,int end){
    if(beg<end){
        int pivot_pos=partition(arr,beg,end);
        quicksort(arr,beg,pivot_pos-1);
        quicksort(arr,pivot_pos+1,end);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)    cin>>arr[i];
    quicksort(arr,0,n);
    cout<<"Print the elements: ";
    for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
    return 0;
}
