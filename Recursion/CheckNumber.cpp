#include <iostream>
using namespace std;

bool CheckNumber(int a[], int size,int item){
    if(size == 0 ){
        return false;
    }
    if(a[0] == item){
        return true;
    }
    return CheckNumber(a+1,size-1,item);
}


int main(){
    int arr[] = {2,3,4,5,6,7,8};
    cout<<CheckNumber(arr,7,5);
}