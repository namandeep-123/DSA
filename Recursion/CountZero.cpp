#include <iostream>
// #include "solution.h"
using namespace std;

int countZeros(int n)
{
    if (n <= 9)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int lastNumber = n % 10;
    int smallNumber = n / 10;
    int ans = countZeros(smallNumber);
    if (lastNumber == 0)
    {
        return ans + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
    // cout << 002 << endl;
    // cout << 1 % 10;
    // return 0;
}
