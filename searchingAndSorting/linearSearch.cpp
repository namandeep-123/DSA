#include <iostream>
using namespace std;

int linearSearch(int arr[], int arrayLength,int item){
    for (int i = 0; i<arrayLength; i++){
        if (arr[i] == item){
            return i;
        }
    }

}

int main() {
    int number,item,arrayLength;
    int arr[100];
    cout << "Enter how many array you want to enter :" << " ";
    cin >> number;
    for (int i = 0; i < number; i++){
        cout << "Enter Array length" << " ";
        cin >> arrayLength;
        for (int i = 0; i<arrayLength; i++){
            cin >> arr[i];
        }
        cout << "Enter element to search" << " ";
        cin >> item;
        int itemSearch = linearSearch(arr,arrayLength,item);
        cout << itemSearch << endl;
        

    }
}