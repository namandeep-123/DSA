#include <iostream>
using namespace std;

void removeHelper(char input[], char newString[], int index,int k){
    if(input[index] == '\0'){
        return;
    }
    if(input[index] != 'x'){
        newString[k] = input[index];
        k++;
    }
    removeHelper(input,newString,index+1, k);
    cout<<newString;
    
}

void removeX(char input[]) {
    char newString[1000];
    removeHelper(input,newString, 0,0);

}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
