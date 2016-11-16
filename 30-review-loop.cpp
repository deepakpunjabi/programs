#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t;
    cin>>t;
    vector<string> s(t);

    for(int i=0; i<t; i++)
    {
        cin>>s[i];
    }

    for(int i=0; i<t; i++)
    {
        cout<<"hey";
        for(int j=0; j<s[i].length(); j+=2)
        {
            cout<<s[i][j];

        }
        cout<<"hey1";
        cout<<" ";
        for(int j=1; j<s[i].length(); j+=2)
        {
            cout<<s[i][j];
        }

        cout<<"he23y";
        cout<<endl;
    }
    return 0;
}
