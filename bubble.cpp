#include<stdio.h>
#include<iostream>
using namespace std;
void bubble(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int a[]={64, 25, 12, 22, 11,-12,1035,0};
    int size = sizeof(a)/sizeof(a[0]);
    bubble(a,size);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
