#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int k = 0;
    int loop=0;
    for(int i=1;i<=10;i+=2){
        k=k+2*i;
        k+=1;
        loop++;
        if(loop==3){
            cout<<k<<endl;
            return 1;
        }
    }
    return 0;
}
