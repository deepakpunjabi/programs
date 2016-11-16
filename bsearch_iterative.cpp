#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int mid,a[]={1,2,3,4,5,6};
    int n=(sizeof(a)/sizeof(a[0]));
    int k=7;
    int l=0;
    int h=n-1;
    while(l<=h){
        mid = (l+h)/2;
        if(a[mid]==k){
            cout<<mid;
            return k;
        }
        else if(a[mid]<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }

    }
    cout<<-1;
    return -1;
}
