#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));

    cout << fixed;

    if (d > 0)
    {
        cout << "roots are real and Different : " << endl;
        cout << setprecision(4) << (double)(((double)-b + (double)(sqrt_val)) / (double)(2 * a)) << " ";
        cout << setprecision(4) << (double)(((double)-b - (double)(sqrt_val)) / (double)(2 * a)) << endl;
    }

    else if (d == 0)
    {
        cout << "roots are real and same : " << endl;
        cout << (double)-b / (2 * a);
    }
    else
    {
        cout << "roots are different and Complex : " << endl;
        cout << (double)-b / (2 * a) << " + " << sqrt_val / (2 * a) << "i" << endl;
        cout << (double)-b / (2 * a) << " - " << sqrt_val / (2 * a) << "i" << endl;
    }
}