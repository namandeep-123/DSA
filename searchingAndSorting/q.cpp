#include <iostream>
using namespace std;



void merge(int a[], int start, int mid, int end){
    int size = end - start +1;
    int* out = new int[size];
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j <= end){
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
        j++;
        k++;
    }
    int m =0;
    for(int i = start; i<=end; i++){
        a[i] = out[m];
        m++;
    }
    delete  [] out;
    
}


void MergeSort(int input[], int start , int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    MergeSort(input,start,mid);
    MergeSort(input,mid+1,end);
    merge(input,start,mid,end);
}

void mergeSort(int input[], int size){
	int start = 0;
    int end = size -1;
    MergeSort(input,start, end);
}



int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}