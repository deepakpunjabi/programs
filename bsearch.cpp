#include<stdio.h>
#include<iostream>

using namespace std;

int bsearch(int a[],int l,int h,int k) {
    if(h<1) {
        return -1;
    }
    int mid = (l+h)/2;
    if(a[mid]==k) {
        return mid;
    } else if(a[mid]>k) {
        return bsearch(a,l,mid-1,k);
    } else {
        return bsearch(a,mid+1,h,k);
    }
}
int main() {
    int a[]= {1,2,3,670};
    cout<<bsearch(a,0,4,670);
    return 0;
}
