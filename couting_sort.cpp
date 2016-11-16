#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a[]={8,5,2,4,9,3,6,2,0,2,5,7,8,3},b[14];
    vector<int> count(10,0);

    for(auto i:a){
        count[i]+=1;
    }

//    for(auto i:count){
//        cout<<i<<" ";
//    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=13;i>=0;i--){
        int position = count[a[i]]-1;
        b[position]=a[i];
        count[a[i]]-=1;
    }

    for(auto i:b){
        cout<<i<<" ";
    }
    return 0;
}
