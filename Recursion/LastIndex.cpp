#include  <iostream>
using namespace std;

int LastIndex(int a[],int size, int item){
    if(size == 0){
        return -1;
    }
    int ans = LastIndex(a+1,size-1,item);
    if (ans != -1){
        return ans +1;
    }
    if(a[0] == item){
        return 0;
    }
    else{
        return -1;
    }
    
}

int main(){
    int arr[] = {2,3,4,5,6,7,7,8};
    cout<<LastIndex(arr,7,7);
}