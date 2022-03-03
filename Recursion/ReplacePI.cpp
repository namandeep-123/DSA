#include <iostream>
#include <string.h>
using namespace std;


// Change in the given string itself. So no need to return or print anything
void replaceHelper(char input[], int index){
    if(input[index] == '\0'){
        return;
    }
    replaceHelper(input,index +1);
    if(input[index] == 'p' && input[index +1] == 'i'){
        for(int i = strlen(input); i>=index+2; i--){
            input[i +2] = input[i];
        }
        input[index] = '3';
        input[index + 1] = '.';
        input[index + 2] = '1';
        input[index + 3] = '4';
        
    }
}


void replacePi(char input[]) {
	replaceHelper(input, 0);

}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
