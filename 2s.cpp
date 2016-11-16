#include <bits/stdc++.h>

using namespace std;
bool validate(map<int,int> &a, int no, int k)
{
    int cnt = 0;
    for (auto i : a)
    {
        if (no % i.first == 0)
        {
            cnt+=i.second;
        }
        if (cnt >= k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, t, q, x, k;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[t] += 1;
    }
    cin >> q;
    while (q--)
    {
        cin >> x >> k;
        if (validate(a, x, k))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
