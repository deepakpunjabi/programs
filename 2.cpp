#include <bits/stdc++.h>

using namespace std;
bool validate(vector<int> &a, int no, int k)
{
    int cnt = 0;
    for (auto i : a)
    {
        if (no % i == 0)
        {
            cnt++;
        }
        if (cnt == k)
        {
            return true;
        }
    }
    return false;
}

void print(vector<bool> &r)
{
    for (auto i : r)
    {
        if (i)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

void calc(vector<int> &a, list<pair<int, pair<int, int>>> &q)
{
    vector<bool> r(q.size(), false);
    int fcount = q.size();
    for (auto i : a)
    {
        for (auto j : q)
        {
            if (j.first % i == 0)
            {
                j.second.second--;
                if (j.second.second == 0)
                {
                    r[j.second.first] = true;
                    q.erase(j);
                    fcount--;
                    if (fcount == 0)
                    {
                        print(r);
                        return;
                    }
                }
            }
        }
    }
    print(r);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vector<int> a;
    list<pair<int, pair<int, int>>> q;

    int n, t, q1, i, no, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    cin >> q1;
    for (i = 0; i < q1; i++)
    {
        cin >> no >> k;
        q.push_back({no, {k, i}});
        // if (validate(a, no, k))
        // {
        //     cout << "Yes" << endl;
        // }
        // else
        // {
        //     cout << "No" << endl;
        // }
    }

    calc(a, q);
    return 0;
}
