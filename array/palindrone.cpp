#include <iostream>
using namespace std;

int Length(char arr[]){
    int count  = 0;
    for (int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
    
}

bool Palindrone(char str[]){
    int length = Length(str);
    int i =0, j = length-1,temp;
    for (; i < j; i++, j--){
        if (str[i] == str[j])
        {
            continue;
        }
        else{
            cout<<"Not a Palindrone";
            return false;
        }
        
    }
    return true;

    
    
    
}


int main(){
    char str[100];
    cout <<"Enter the word to check it's palindrone or not : ";
    cin >> str;
    bool ans = Palindrone(str);
    if(ans){
        cout << "Palindrone";
    }
}