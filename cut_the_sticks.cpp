#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,count=0;
    cin >> n;
    vector<int> a(n);
    for(i = 0;i < n;i++){
       cin >> a[i];
    }

    while(a.size()!=0){
        int min = *min_element(a.begin(),a.end());
        cout<<a.size()<<endl;
        for(i=0;i<a.size();i++){
            a[i]-=min;
            if(a[i]<=0){
                a.erase(a.begin()+i);
                i--;
            }
        }
    }
    return 0;
}
