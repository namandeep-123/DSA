#include <iostream>
using namespace std;


void wavePrint(int a[][100],int row,int col){
    //input 
    cout << "Enter 2D Array:" << endl;
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cin >> a[i][j];
        }
        
    }
    cout << "2D Array:" << endl;
    //Printing
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cout << a[i][j] << " ";
        }
        cout << endl;
        
    }
    cout<< "Wave Print : "<<endl;
    for(int j =0;j<col; j++){
        if(j%2 == 0){  
            for (int i = 0; i < row; i++){
                cout<<a[i][j] << " ";
            }
        }
        else{
            for (int i = row-1; i >= 0; i--){
                cout<<a[i][j]<< " ";
            }

        }
        cout<< endl;
        
    }
}    

int main(){
    int a[100][100];
    int m,n;
    cout << "enter Row and column you want to print: ";
    cin >> m >> n;
    wavePrint(a,m,n);
}