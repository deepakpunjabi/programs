#include<stdio.h>
#include<iostream>
#define nl cout<<endl;
using namespace std;

int main(){
    long long t=1,v,temp,ut;

    v=3;
    temp=v+1;

    cin>>ut;

    while(temp--){
        if(t==ut){
            cout<<temp<<endl;
            return 1;
        }
        if(temp==1){
            v*=2;
            temp=v+1;
        }
        t++;
    }

    return 0;
}
