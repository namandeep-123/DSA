#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
pair<int, int> getMinMax(vector<int> &arr, int n)
{
    pair<int, int> minmax;
    int i;

    if (n == 1)
    {
        minmax.first = arr[0];
        minmax.second = arr[0];
        return minmax;
    }

    if (arr[0] > arr[1])
    {
        minmax.first = arr[0];
        minmax.second = arr[1];
    }
    else
    {
        minmax.first = arr[1];
        minmax.second = arr[0];
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.first)
            minmax.first = arr[i];

        else if (arr[i] < minmax.second)
            minmax.second = arr[i];
    }
    return minmax;
}

// Divide and Conqueuer
int noOfComparision = 0;
pair<int, int> getMinMaxRecursion(vector<int> &arr, int low, int high)
{
    pair<int, int> minmax, minmaxleft, minmaxright;
    int mid;

    if (low == high)
    {
        minmax.first = arr[low];
        minmax.second = arr[low];
        return minmax;
    }

    if (high == low + 1)
    {
        noOfComparision += 1;
        if (arr[low] > arr[high])
        {
            minmax.second = arr[low];
            minmax.first = arr[high];
        }
        else
        {
            minmax.second = arr[high];
            minmax.first = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    minmaxleft = getMinMaxRecursion(arr, low, mid);
    minmaxright = getMinMaxRecursion(arr, mid + 1, high);
    noOfComparision += 2;
    if (minmaxleft.first < minmaxright.first)
        minmax.first = minmaxleft.first;
    else
        minmax.first = minmaxright.first;

    if (minmaxleft.second > minmaxright.second)
        minmax.second = minmaxleft.second;
    else
        minmax.second = minmaxright.second;

    return minmax;
}

int main()
{
    file_i_o();
    vector<int> arr = {1, 200, 4000, 56, 19, 20};

    pair<int, int> minmax = getMinMax(arr, arr.size());
    pair<int, int> minmaxRecursion = getMinMaxRecursion(arr, 0, arr.size() - 1);

    cout << "Maximum Element : " << minmax.first << endl;
    cout << "Minimum Element : " << minmax.second << endl;
    cout << "Maximum Element recursively : " << minmaxRecursion.second << endl;
    cout << "Minimum Element recursively : " << minmaxRecursion.first << endl;
    cout << "Number Of Comparision : " << noOfComparision << endl;
    return 0;
}