#include <stdio.h>
#include <iostream>
#define uli unsigned long int
using namespace std;

uli bicoff(uli n, uli k)
{
    uli res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
uli total(int n)
{
    uli res = bicoff(2 * n, n);
    return res / (n + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << total(n);
    return 0;
}
