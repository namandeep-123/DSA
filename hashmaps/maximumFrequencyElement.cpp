#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(int *a, int size)
{
    vector<int> outpput;
    unordered_map<int, int> number(10);
    for (int i = 0; i < size; i++)
    {
        number[a[i]]++;
    }
    int maxCount = -1;
    for (int i = 0; i < number.size(); i++)
    {
        if (maxCount < number[i])
            maxCount = number[i];
    }
    return maxCount;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1};
    cout << maximumFrequency(arr, 14);
}