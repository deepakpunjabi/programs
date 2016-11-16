#include <iostream>
using namespace std;
int largemul(int *a, int n)
{
    int m1, m2, m3, m4;
    m1 = m3 = max(a[0], a[1]);
    m2 = m4 = min(a[1], a[0]);

    for (int i = 2; i < n; i++)
    {
        if (a[i] < m2)
        {
            //do nothing
        }
        else if (a[i] > m2 && a[i] < m1)
        {
            m2 = a[i];
        }
        else
        {
            m2 = m1;
            m1 = a[i];
        }

        if (a[i] > m3)
        {
            //do nothing
        }
        else if (a[i] < m3 && a[i] > m4)
        {
            m3 = a[i];
        }
        else
        {
            m3 = m4;
            m4 = a[i];
        }
    }
    return max(m1 * m2, m3 * m4);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << largemul(a, n);
    return 0;
}