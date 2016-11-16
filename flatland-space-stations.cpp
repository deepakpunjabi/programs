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
    int m;
    cin >> n >> m;
    vector<int> c(m);
    vector<int> dis(n);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        cout<<"i "<<i<<endl;
        for(int j=0;j<m;j++){
            cout<<"j and c[j] "<<j<<" "<<c[j]<<endl;
            if(i==c[j]){
                dis[i]=0;
                break;
            }
            else{
                if(abs(i-c[j])<mini){
                    dis[i]=abs(i-c[j]);
                    mini=dis[i];

                }
                cout<<"dis i inside "<<dis[i]<<endl;
            }
        }
        cout<<"min dis "<<dis[i]<<endl;
    }
    cout<<*max_element(dis.begin(),dis.end());
    return 0;
}
