#include <iostream>
#include <climits>
using namespace std;

void Largest(int a[][100],int row,int col){
    //input 
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cin >> a[i][j];
        }
        
    }
    //Printing
    for (int i = 0; i <row ;i++){
        for (int j = 0; j < col; j++){
           cout << a[i][j] << " ";
        }
        cout << endl;
        
    }


    int maxrowsum = 0,rowsum= 0,rowIndex = 0;
    for(int i =0;i<row;i++){
        for(int j =0; j<col;j++){
            rowsum += a[i][j];

        }
        if(maxrowsum < rowsum){
            maxrowsum = rowsum ;
            rowIndex = i;
        }
        rowsum = 0;
    }
    int maxcolsum = INT_MIN,colsum= 0,colIndex = 0;
    for(int i =0;i<row;i++){
        for(int j =0; j<col;j++){
            colsum += a[j][i];

        }
        if(maxcolsum < colsum){
            maxcolsum = colsum ;
            colIndex = i;
        }
        colsum = 0;
    }
    
    if(maxrowsum > maxcolsum){
        cout<<"Row: "<<rowIndex << " " << maxrowsum;
    }else{
        cout << "column: " << colIndex << " " << maxcolsum;
    }
}


int main(){
    int a[100][100];
    int m,n;
    cout << "enter Row and column you want to print: ";
    cin >> m >> n;
    Largest(a,m,n);
}