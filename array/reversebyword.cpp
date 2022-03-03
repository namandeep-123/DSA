#include <iostream>
using namespace std;

int Length(char arr[]){
    int count  = 0;
    for (int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
    
}

void wordReverse(char input[]){
    int k =0;
    for(int i =0; input[i] != '\0'; i++){
        if (input[i] == ' ' ){
            int j = i-1,temp;
            for(;k<j;k++,j--){
                temp = input[k];
                input[k] = input[j];
                input[j] = temp;
            }
            k=i+1;

        }
    }
    cout << input;
}

void reverseWord(char str[]){
    int length = Length(str);
    int i = 0, j = length-1,temp;
    for(;i<j;i++,j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    wordReverse(str);
    
}


int main(){
    char str[100];
    cout <<"Enter Character : ";
    cin.getline(str,100);
    reverseWord(str);
    
}