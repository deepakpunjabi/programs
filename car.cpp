#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,q;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d %d %d",&n,&k,&q);

    int *a=(int *)malloc(n*sizeof(int));
    int *qs=(int *)malloc(q*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>a[(i+k)%n];
    }

    for(int i=0;i<q;i++){
        cin>>qs[i];
    }
    for(int i=0;i<q;i++){
        cout<<a[qs[i]]<<endl;
    }
    return 0;
}
