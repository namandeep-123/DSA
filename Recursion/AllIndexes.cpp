#include <iostream>
using namespace std;

int recursiveAllIndexes(int a[],int size, int item, int output[]){
    if(size == 0){
        return 0;
    }
    int ans = recursiveAllIndexes(a+1,size-1,item,output);
    if(a[0] == item){
        for(int i = ans-1;i >= 0; i--){
            output[i+1] = output[i] + 1;
        }
        output[0] = 0;
        ans++;
    }
    else{
        for(int i = ans -1 ;i>=0 ; i--){
            output[i] = output[i] + 1;

        }
    }
    return ans;
}

int AllIndexes(int arr[],int size,int item){
    int output[size];
    int outputArraySize = recursiveAllIndexes(arr,size,item,output);
    for(int i =0 ; i< outputArraySize ; i++){
        cout << output[i] << " ";
    }

}

int main(){
    int arr[] = {7,3,4,5,6,7,7,8};
    AllIndexes(arr,8,7);
}