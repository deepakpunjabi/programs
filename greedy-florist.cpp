#include <iostream>
#include <vector>
#include <algorithm>
#define uli unsigned long int
using namespace std;

int cost(vector<uli> &fi, int k)
{
    vector<int> in(k, 1);
    int j = 0;
    int cost = 0;
    for (int i = 0; i < fi.size(); i++)
    {

        cost += in[j] * fi[i];
        in[j]++;
        j++;
        if (j == in.size())
        {
            j = 0;
        }
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, temp;
    cin >> n >> k;
    vector<uli> fi;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        fi.push_back(temp);
    }
    sort(fi.begin(), fi.end(), greater<int>());
    cout << cost(fi, k);
    return 0;
}
