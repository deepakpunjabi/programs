#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n,k,b,sum=0;
    vector<int> c(n);

    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        c[i]=temp;
//        if(i%k!=0)
//            sum+=temp;
    }

    cin>>b;

    if(b==(sum/2))
    {
        cout<<"Bon Appetit";
    }
    else
    {
        cout<<b-sum/2;
    }
    return 0;
}
