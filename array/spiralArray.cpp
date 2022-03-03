#include <iostream>
using namespace std;


void SpiralPrint(int a[][100], int row, int col){
    //input 
    cout << "Enter 2D Array:" << endl;
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cin >> a[i][j];
        }
        
    }
    int top = 0, left =0,right = col-1,down = row-1;
    while (top <= down && left <= right){
        for(int i = left;i<=right;i++){
            cout << a[top][i]<< " ";
        }
        top++;
        for(int i = top;i<=down;i++){
            cout<<a[i][right]<< " ";
        }
        right--;
        for(int i = right; i >= left; i--){
            cout<<a[down][i] << " ";
        }
        down--;
        for(int i = down;i>=top; i--){
            cout<< a[i][left] << " ";
        }
        left++;
        
    }
    
    
        
        
}



int main(){
    int a[100][100];
    int m,n;
    cout << "enter Row and column you want to print: ";
    cin >> m >> n;
    SpiralPrint(a,m,n);
}