#include <iostream>
#include <vector>
using namespace std;

vector<int> lcs(string x, string y)
{
    // string y = "linkedin";
    int res = 0;
    int endx, endy;
    vector<int> vec;
    int m, n, index;
    m = x.length();
    n = y.length();
    int mat[m + 1][n + 1];
    // vector<vector<int>> mat(m+1,vector<int> (n+1,0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                if (res < mat[i][j])
                {
                    res = mat[i][j];
                    endx = i - 1;
                    endy = j - 1;
                    // cout << i-1 << " "<< j-1 << endl;
                }
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }
    // starty = endy - res + 1;
    vec.push_back(res);
    vec.push_back(endx - res + 1);
    vec.push_back(endx);
    vec.push_back(endy - res + 1);
    vec.push_back(endy);

    // cout<<endl;
    // for(auto i:mat){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=starty;i<=endy;i++){
    //     cout<<y[i];
    // }
    // cout<<endl;
    return vec;
    // return make_pair(res, index);
    // return res;
}

int findCost(string x, string y)
{
    // pair<int, int> l1, l2, l;
    // l1 = lcs(x,"linkedin");
    // l2 = linlen(y,"linkedin");
    // // cout<<l1<<"\t"<<l2<<endl;
    // cout << l1.second - l1.first + 1 << " " << l1.second << endl;
    // cout << l2.second - l2.first + 1 << " " << l2.second << endl;

    // if (l1.first >= l2.first)
    // {
    //     l = make_pair(l1.second - l1.first + 1, l1.second);
    // }
    // else
    // {
    //     l = make_pair(l2.second - l2.first + 1, l2.second);
    // }

    vector<int> l1, l2;
    l1 = lcs(x, "linkedin");
    l2 = lcs(y, "linkedin");

    // for (auto i : l1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : l2)
    // {
    //     cout << i << " ";
    // }

    
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    string x, y;
    cin >> x >> y;
    findCost(x, y);
    return 0;
}
