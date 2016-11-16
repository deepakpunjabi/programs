#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    bool flag=true;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;
        if(k==0)
        {
            for(int i=1; i<=n; i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        if(n%k==0 && n%2==0)
        {
            for(int i=1; i<=(n/k); i++)
            {
                /*if(k+i > n)
                {
                    cout<<abs(k-i)<<" ";
                }
                else
                {
                    cout<<k+i<<" ";
                }*/
                if(i%2!=0){
                    cout<<k+i<<" ";
                }
                else{
                    cout<<abs(k-i)<<" ";
                }

            }
            cout<<endl;

        }
        else
        {

            cout<<"-1"<<endl;
        }

    }
    return 0;
}
