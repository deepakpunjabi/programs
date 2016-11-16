#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> a,b;
    vector<int> cache(100,0);
    int as,bs,min=INT_MAX;
    cin>>as;
    cout<<1<<endl;
    for(int i=0;i<as;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    cout<<2<<endl;
    cin>>bs;
    for(int i=0;i<bs;i++){
        int t;
        cin>>t;
        b.push_back(t);
        if(t<min)
            min=t;
    }
    cout<<3<<endl;
    for(auto i:b){
        cache[i-min]+=1;
    }
    cout<<4<<endl;
    for(auto i:a){
        cache[i-min]-=1;
    }
    cout<<5<<endl;
    for(int i=0;i<cache.size();i++){
        if(cache[i]!=0)
            cout<<i+min<<" ";
    }
    cout<<6<<endl;
    return 0;
}
