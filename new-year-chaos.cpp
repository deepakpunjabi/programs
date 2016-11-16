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
    int T;
    cin >> T;
    bool flag=false;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        int swap=0;
        flag=false;
        cin >> n;
        vector<int> q(n);
        for(int i = 0;i < n;i++){
           cin >> q[i];
        }
        // your code goes here
        for(int i=0;i<n;){
            if(q[i]-(i+1)>2){
                cout<<"Too chaotic"<<endl;
                flag=true;
                break;
            }
            else if(q[i]-(i+1)==2){
                if(q[i+1]!=q[i]-2 && q[i+2]!=q[i]-1){
                    cout<<"Too chaotic"<<endl;
                    flag=true;
                    break;
                }
                swap+=2;
                i+=3;
            }
            else if(q[i]-(i+1)==1){
                /*if(q[i+1]!=q[i]-1 || q[i+1]!=q[i]+1){
                    cout<<"Too chaotic"<<endl;
                    flag=true;
                    break;
                }
                swap+=1;
                i+=2;*/
                if(q[i+1]==q[i]-1){
                    swap+=1;
                    i+=2;
                }
                else if(q[i+2]==q[i]-1 && q[i+1]==q[i]+1){
                    swap+=2;
                    i+=3;
                }
                else{
                    cout<<"Too chaotic"<<endl;
                    flag=true;
                    break;
                }
            }
            else if(q[i]-(i+1)==0){
                i++;
            }
            else{
                    cout<<"Too chaotic"<<endl;
                    flag=true;
                    break;
            }
        }
        if(!flag){
            cout<<swap<<endl;
        }
    }
    return 0;
}
