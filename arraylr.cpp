#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,d;
    cin>>n>>d;
    vector<double> a(n);
    for(int i=0;i<n;i++){
        if(i-d <0){
            cin>>a[(n-1)-(i-d)];
        }
        else{
            cin>>a[i-d];
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
