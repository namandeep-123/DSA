#include <bits/stdc++.h>
using namespace std;
#define d 256

int main()
{
    string txt, pat;
    cout << "Enter Text";
    cin >> txt;
    cout << "Enter Pattern";
    cin >> pat;
    int hpat = 0, htxt = 0;
    int primeNumber = 101;
    for (int i = 0; i < pat.size(); i++)
    {
        hpat *= d;
        hpat = hpat + ((pat[i] - 'A' + 1) % primeNumber);
    }
    int left = 0, r = 0;
    while (r < txt.size())
    {
        htxt *= d;
        htxt = htxt + ((txt[r] - 'A' + 1) % primeNumber);
        if (r - left + 1 == pat.size())
        {
            if (hpat == htxt)
                cout << "Match At " << left << endl;
            htxt = htxt - ((txt[left] - 'A' + 1) * pow(d, r - left));
            left++;
        }
        r++;
    }
}