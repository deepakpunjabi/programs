#include <iostream>
#include <vector>
using namespace std;

vector<int> createlps(string y)
{
    vector<int> a(y.length(), 0);
    int j = 0;
    int i = 1;
    while (i < y.length())
    {
        if (y[i] == y[j])
        {
            a[i++] = ++j;
        }
        else
        {
            if (j != 0)
            {
                j = a[j - 1];
            }
            else
            {
                a[i++] = 0;
            }
        }
    }
    return a;
}

void kmp(string x, string y)
{
    vector<int> a = createlps(y);
    int i, j;
    i = j = 0;
    while (i < x.length())
    {
        if (x[i] == y[j])
        {
            i++;
            j++;
        }
        if (j == y.length())
        {
            cout << "Pattern at : " << i - j << endl;
            j = a[j - 1];
        }
        else if (i < x.length() && x[i] != y[j])
        {
            if (j != 0)
            {
                j = a[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    string str, pat;
    str = "ABABDABACDABABCABAB";
    pat = "ABABCABAB";
    kmp(str, pat);
    return 0;
}
