#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k,e=100,i;

    cin>>n>>k;
    vector <int> c(n);
    for(i=0;i<n;i++){
        cin>>c[i];
    }
    i=0;
    while(e){
        i=(i+k)%n;
        if(c[i]==1)
            e-=3;
        else
            e-=1;
        //cout<<c[i]<<e<<endl;
        if(i==0){
            cout<<e;
            return 1;
        }
    }
    return 0;
}
