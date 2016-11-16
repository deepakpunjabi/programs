#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int a[]={1,5,6,3,2,18,-1,0};

    int i,j,k,n,key;
    //cout<<a[5];
    n=sizeof(a)/sizeof(a[0]);
    for(i=1;i<n;i++){
        key=a[i];
        /*for(j=i-1;j>=0,a[j]>key;j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;*/

        for(j=i-1;j>=0,a[j]>key;j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }

    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
