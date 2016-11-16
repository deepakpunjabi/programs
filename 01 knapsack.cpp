#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n){
    int m[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j==0 || i==0)
                m[i][j]=0;
            else if(wt[i]<=W)
                m[i][j]=max(val[i-1]+m[i-1][j-wt[i-1]],m[i-1][j]);
            else
                m[i][j]=m[i-1][j];
        }
    }


    return m[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
