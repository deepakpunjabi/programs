#include <iostream>
#include <climits>
using namespace std;
int shift(int s[], int n, int i)
{
    int count = 0;
    int j = 0;
    int k = i;
    while (j < k)
    {
        if (s[j] == 0)
        {
            j++;
        }
        else if (s[k] == 1)
        {
            k--;
        }
        else
        {
            s[k] = s[j];
            s[j] = 0;
            count += k - j;
            j++;
            k--;
        }
    }
    j = n - 1;
    k = i;
    while (j > k)
    {
        if (s[j] == 0)
        {
            j--;
        }
        else if (s[k] == 1)
        {
            k++;
        }
        else
        {
            s[k] = s[j];
            s[j] = 0;
            count += j - k;
            j--;
            k++;
        }
    }
    return count;
}
int findMedian(int s[], int n)
{
    int count1 = 0;
    for (int c = 0; c < n; c++)
    {
        if (s[c] == 1)
        {
            count1++;
        }
    }
    if (count1 == 0)
    {
        return -1;
    }
    count1 = (count1 + 1) / 2;
    int count2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 1)
        {
            count2++;
            if (count2 == count1)
            {
                return i;
            }
        }
    }
}
int monkey(int s[], int n)
{
    int i = findMedian(s, n);
    if (i == -1)
    {
        return 0;
    }
    return shift(s, n, i);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = monkey(arr, n);
    cout << res << endl;
}