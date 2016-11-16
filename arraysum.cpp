#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a[]={1,5,2,5,1};
    int sum=5;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]+a[j]==sum && i!=j){
                cout<<"success"<<endl;
                return 1;
            }
        }
    }
    cout<<"failure"<<endl;
    return 0;
}
