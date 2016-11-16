#include <bits/stdc++.h>
using namespace std;


int c[1002][1002];
int p[1002][1002];
int dp1[1002][1002];
int dp2[1002][1002];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> c[i][j];
                dp1[i][j] = 0;
                dp2[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> p[i][j];
            }
        }
        dp1[0][0] = c[0][0];
        dp2[0][0] = c[0][0];
        for(int i=1; i<n; i++){
            dp2[i][0] = min(dp2[i-1][0] + c[i][0], dp1[i-1][0] + c[i][0] + p[i-1][0]);
            dp1[i][0] = dp2[i][0] + p[i][0];
        }
        for(int j=1; j<m; j++){
            dp1[0][j] = (dp1[0][j-1] + c[0][j]);
            dp2[0][j] = dp1[0][j] + p[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp1[i][j] = min(dp2[i-1][j]+c[i][j]+p[i][j], dp1[i-1][j] + p[i-1][j] + c[i][j]+p[i][j]);
                dp1[i][j] = min(dp1[i][j],min(dp2[i][j-1]+p[i][j-1]+c[i][j], dp1[i][j-1]+c[i][j]));
                dp2[i][j] = min(dp2[i-1][j]+c[i][j], dp1[i-1][j]+p[i-1][j]+c[i][j]);
                dp2[i][j] = min(dp2[i][j],min(dp1[i][j-1]+c[i][j]+p[i][j],dp2[i][j-1]+p[i][j-1]+c[i][j]+p[i][j]));
            }
        }
        cout << min(dp1[n-1][m-1],dp2[n-1][m-1]) << endl;
    }
    return 0;
}

