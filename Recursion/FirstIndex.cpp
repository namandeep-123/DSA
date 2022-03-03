#include <iostream>
using namespace std;


int FirstIndex(int a[],int size, int item){
    if(size == 0){
        return -1;
    }

    if(a[0] == item){
        return 0;
    }

    int ans = FirstIndex(a+1,size-1,item);
    if(ans == -1){
        return -1;
    }else{
        return ans+1;
    }
}

int main(){
    int arr[] = {2,3,4,5,6,7,8};
    cout<<FirstIndex(arr,7,7);
}