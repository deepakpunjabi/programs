#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    vector<string> s;
    // map<char, bool> m1(26, false), m2(26, false);
    vector<bool> v1(26,false),v2(26,true);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s.push_back(t);
    }

    bool a = false;
    for (auto i : s)
    {
        for (auto j : i)
        {
            if(a)
            {
                if(v1[j-'0'])
                    v2[j-'0']=true;
            }
            else
            {
                if(v2[j-'0'])
                    v1[j-'0'] = true;

            }
        }
        if(a)
        {
            a=false;
            v1.assign(v1.size(),false);
        }
        else
        {
            a=true;
            v2.assign(v2.size(),false);
        }
    }
    
    return 0;
}
