#include<bits/stdc++.h>
#define r 3
#define c 3
using namespace std;

int minCost(int cost[r][c],int si,int sj){
    int m[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 && j==0){
                m[i][j]=cost[i][j];
            }
            else if(i==0 && j!=0){
                m[i][j]=m[i][j-1]+cost[i][j];
            }
            else if(i!=0 && j==0){
                m[i][j]=m[i-1][j]+cost[i][j];
            }
            else{
                m[i][j]=cost[i][j]+min(m[i-1][j],min(m[i-1][j-1],m[i][j-1]));
            }
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return m[r-1][c-1];
}
int main(){
    int cost[r][c] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};
    cout<<minCost(cost,2,2);
    return 0;
}
