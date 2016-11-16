#include <bits/stdc++.h>

using namespace std;

int f1(int a, long long int b, long long int d, long long int m)
{
    long long t;
    t = (b - a) / d + (((b - a) % d) > 0);
    a = (a * t) % m + (t % 2);
    return a % m;
}

int f(int a, long long int b, long long int d, long long int m)
{
    int s = 0;
    while (a < b)
    {
        s += (a ^ 1);
        a += d;
    }
    return (s % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int q, d;
    cin >> q;
    long long int a, b, m;
    while (q--)
    {
        cin >> a >> b >> d >> m;
        cout << f1(a, b, d, m) << endl;
    }
    return 0;
}
