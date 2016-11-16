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


int main(){
    int n;
    int k;
    int i,j;
    int m1,i1,m2,i2;
    int maxsum,tempsum;
    int count=0;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    sort(a.begin(),a.end());
    maxsum = a[n-2]+a[n-1];
    /*for(i=0;i<n;i++){
        cout<<a[i];
    }*/
    //cout << maxsum;
    /*m1=a[0];

    for(i=0;i<n;i++){
        if(m1<a[i]){

        }
    }*/
    for(k=1;k<=100;k++){
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                tempsum=a[i]+a[j];
                if(tempsum%k==0){
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}
