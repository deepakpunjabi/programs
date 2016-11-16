#include <bits/stdc++.h>
using namespace std;


int i1[1002][1002];
int i2[1002][1002];
int dp1[1002][1002];
int dp2[1002][1002];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> i1[i][j];
                dp1[i][j] = 0;
                dp2[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> i2[i][j];
            }
        }
        dp1[0][0] = i1[0][0];
        dp2[0][0] = i1[0][0];
        for(int i=1; i<n; i++)
        {
            dp2[i][0] = min(dp2[i-1][0] + i1[i][0], dp1[i-1][0] + i1[i][0] + i2[i-1][0]);
            dp1[i][0] = dp2[i][0] + i2[i][0];
        }
        for(int j=1; j<m; j++)
        {
            dp1[0][j] = (dp1[0][j-1] + i1[0][j]);
            dp2[0][j] = dp1[0][j] + i2[0][j];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                dp1[i][j] = min(dp2[i-1][j]+i1[i][j]+i2[i][j], dp1[i-1][j] + i2[i-1][j] + i1[i][j]+i2[i][j]);
                dp1[i][j] = min(dp1[i][j],min(dp2[i][j-1]+i2[i][j-1]+i1[i][j], dp1[i][j-1]+i1[i][j]));
                dp2[i][j] = min(dp2[i-1][j]+i1[i][j], dp1[i-1][j]+i2[i-1][j]+i1[i][j]);
                dp2[i][j] = min(dp2[i][j],min(dp1[i][j-1]+i1[i][j]+i2[i][j],dp2[i][j-1]+i2[i][j-1]+i1[i][j]+i2[i][j]));
            }
        }
        cout << min(dp1[n-1][m-1],dp2[n-1][m-1]) << endl;
    }
    return 0;
}


