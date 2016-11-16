#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a;
        cin >> b;

        int i,j,m,n;

        m = a.size();
        n = b.size();
        vector< vector<int> > lcs(m+1, vector<int> (n+1,0));

        for(i=0; i<=m; i++)
        {
            for(j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                {
                    lcs[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1]+ (a[i-1]-'0');
                else
                {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        // cout << lcs[m][n] << endl;
        int val = lcs[m][n];
        int sum1= 0, sum2 =0;
        for(i=0; i<m; i++) sum1 = sum1 + (a[i]-'0');
        for(i=0; i<n; i++) sum2 = sum2 + (b[i]-'0');
        // cout << sum1 << " " << sum2 << endl;

        int res = abs(sum1-val) + abs(sum2-val);
        cout << res << endl;
    }
    return 0;
}
