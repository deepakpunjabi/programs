#include<bits/stdc++.h>
#define M 100

using namespace std;

void printa(int a[M][M],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int n,a[M][M];
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=1;
        }
    }
    printa(a,n);
    return 0;
}
