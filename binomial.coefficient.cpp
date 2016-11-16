#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k)
{
    int m[n+1][k+1];
    int i,j;

    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(j==0 || j==i)
                m[i][j]=1;
            else
                m[i][j]=m[i-1][j-1]+m[i-1][j];

            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return m[n][k];
}

int main()
{
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
    return 0;
}
