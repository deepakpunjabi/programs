#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define nl cout<<endl;
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,i,count=0,e;
    vector <int> a(k);
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>e;
        a[e%k]+=1;
    }
    cout<<"-----------array------------\n";
    for(i=0;i<k;i++){
        cout<<a[i]<<" ";
    }
    if(a[0]!=0){
        count=1;
    }
    nl;
    cout<<"-----------value of k/2------------\n";
    cout<<k/2;
    cout<<endl;
    for(i=1;i<=(k/2);i++){
        count += max(a[i],a[k-i]);
    }
    printf("%d",count);
    return 0;
}
