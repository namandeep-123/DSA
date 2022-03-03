#include <iostream>
using namespace std;

int StringSequence(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallAns = input.substr(1);
    int Ans = StringSequence(smallAns,output);
    for(int i = 0; i<Ans; i++){
        output[i+Ans] = input[0] + output[i];
        
    }
    return 2*Ans;
}

int main(){
    string str;
    cin>>str;
    string strArray[100];
    int count =StringSequence(str,strArray );
    for(int i =0;i<count;i++){
        cout<<strArray[i] << endl;
    }



}