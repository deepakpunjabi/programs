#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int i, int n)
{
    int l, r, large = i;
    // n = a.size();
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && a[l] > a[large])
    {
        large = l;
    }
    if (r < n && a[r] > a[large])
    {
        large = r;
    }
    if (large != i)
    {
        swap(a[i], a[large]);
        heapify(a, large, n);
    }
}
void heapSort(vector<int> &a)
{
    int n = a.size();
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

void print(vector<int> &a)
{
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    vector<int> a;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    // print(a);
    heapSort(a);
    print(a);
    return 0;
}
