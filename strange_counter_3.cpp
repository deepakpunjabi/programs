#include<stdio.h>
#include<iostream>
#define p(x) cout<<x
#define pt(x) cout<<x<<"\t"
#define nl cout<<endl;
using namespace std;

int main(){
    long long i=1,t=1,v,temp,ut;

    cin>>ut;
    //int j=3;
    while(true){

        v=3*i;

        /*if(t+v>ut){
            int tv=v;
            int tt=t;
            while(tt!=ut){
                tt++;
                tv--;
            }
            cout<<tv;
            return 1;
        }
        else if(t+v==ut){
            cout<<v*2;
            return 1;
        }*/
        if(t>ut){
            cout<< t-ut;
            return 1;
        }
        /*pt("value");
        p(v);
        pt("");
        pt("i");
        p(i);
        pt("");
        pt("t");
        p(t);
        nl;*/
        i*=2;
        t+=v;

    }
    return 1;
}
