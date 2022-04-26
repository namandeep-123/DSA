#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bt(n), wt(n), tat(n), at(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival Time : " << i + 1 << " ";
        cin >> at[i];
    }
    cout << "Enter Burst Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Burst Time : " << i + 1 << ' ';
        cin >> bt[i];
    }
    wt[0];
    tat[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1] + at[i - 1] - at[i];
        tat[i] = bt[i] + wt[i];
    }

    // Print

    for (int i = 0; i < n; i++)
    {
        cout << "Waiting Time and Turn Around Time : ";
        cout << wt[i] << " " << tat[i] << endl;
    }
}