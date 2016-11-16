#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;

    cin>>n;
    vector<string> str(n);
//    for(int i=0;i<n;i++){
//        cout<<str[i]<<endl;
//    }

    for(int i=0;i<n;i++){
        cin>>str[i];
    }

//    for(auto i:str)
//        cout<<i<<endl;


    cin>>q;
    for(int i=0;i<q;i++){
        string query;
        cin>>query;
        cout<<count(str.begin(),str.end(),query)<<endl;
    }
    return 0;
}
