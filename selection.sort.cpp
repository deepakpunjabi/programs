#include<stdio.h>
#include<iostream>
using namespace std;

void selsort(int a[], int n){
    int i,j,mini,temp;
    //cout<<"size "<<n<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    for(i=0;i<n-1;i++){
        mini=i;
        //cout<<endl<<i<<endl;
        for(j=i+1;j<n;j++){
            //cout<<j<<" ";
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
    cout<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int main(){
    int a[]={64, 25, 12, 22, 11,-12,1035,0};
    int size = sizeof(a)/sizeof(a[0]);
    selsort(a,size);

    return 0;
}
