#include <iostream>
using namespace std;


void colWiseSum(int a[][100],int row, int col){
    int sum= 0;
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cin >> a[i][j];
        }
        
    }
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cout << a[i][j] << " ";
        }
        cout <<endl;
        
    }
    for (int j = 0; j <col ;j++){
        for (int i = 0; i < row; i++){
            sum +=a[i][j];
        }
        cout<<sum<< " ";
        sum = 0;
        
    }
    
    
}

int main(){
    int a[100][100];
    int m,n;
    cout << "enter Row and column you want to print";
    cin >> m >> n;
    colWiseSum(a,m,n);
}