#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> &b, int k)
{
    int last1, t, i;
    int ans = INT_MAX;
    for (i = 1; i < b.size(); i++)
    {
        if (b[i] == 1)
        {
            last1 = i;
            break;
        }
    }
    for (i = last1 + 1; i < b.size(); i++)
    {
        if (b[i] == 1)
        {
            t = last1 + (i - last1) * k;
            if (t < ans)
            {
                ans = t;
                last1 = i;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, t = 0, k;
    int last1 = 0;
    cin >> n >> k;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        b.push_back(t);
    }

    while (t != 1)
    {
        cin >> t;
        last1++;
    }
    for (i = last1; i < b.size(); i++)
    {
        cin >> t;
        if (t == 1)
        {
            t = last1 + (i - last1) * k;
            if (t < ans)
            {
                ans = t;
                last1 = i;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
