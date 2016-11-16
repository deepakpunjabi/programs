#include <bits/stdc++.h>

using namespace std;
int lis(int a[], int n)
{
    vector<int> la(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(a[j]<a[i])
            {
                la[i]=max(la[i],la[j]+1);
            }
        }
    }
    return *max_element(la.begin(),la.end());
}
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));

    return 0;
}
