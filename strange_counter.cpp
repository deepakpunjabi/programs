#include<stdio.h>
#include<iostream>
#define nl cout<<endl;
using namespace std;

int main(){
    long long t=1,v,temp,ut;

    v=3;
    temp=v;

    cin>>ut;

    while(true){
        //cout<<temp;

        cout<<t<<"\t"<<temp;
        nl;
        if(t==ut){
            cout<<temp;
            return 1;
        }



        if(temp==1){
            v*=2;
            temp=v+1;
        }

        temp--;
        t++;
    }

    return 0;
}
