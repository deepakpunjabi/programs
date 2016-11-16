#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define p(key) cout<<key<<endl;
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q,x,y,op,la=0;
    cin>>n>>q;
    p("value of n");
    p(n);
    p("q");
    p(q);
    unordered_map<int,vector<int>> seq(n);

    for(int i=0;i<q;i++){
        p("for loop");
        cin>>op>>x>>y;
        cout<<"op x y : "<<op<<x<<y;
        int index = (x^la)%n;
        cout<<"Index "<<index<<endl;
        if(op==1){
            p("inside if");
            seq[index].push_back(y);
        }
        else{
            p("inside else");
            la=y%seq[index].size();
            cout<<la<<endl;
        }


    }
    p("print map");
    for(auto i:seq){
        cout<<i.first<<" : ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
