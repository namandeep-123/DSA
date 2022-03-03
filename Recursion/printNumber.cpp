#include <iostream>

using namespace std;

int number(int n){
    if(n == 1){
        return 1;
    }
    
    int smallOutput =  number(n-1);
    cout<< smallOutput << " ";
    return n;
}

int main()
{
    cout<<number(10)<<endl;
}
