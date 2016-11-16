#include<bits/stdc++.h>
using namespace std;

int editDist(string x,string y){
    int m=x.length();
    int n=y.length();
    int mat[m+1][n+1];

    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0){
                mat[i][j]=j;
            }
            else if(j==0){
                mat[i][j]=i;
            }
            else if(x[i-1]==y[j-1]){
                mat[i][j]=mat[i-1][j-1];
            }
            else{
                mat[i][j]=1+min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]));
            }
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return mat[m][n];
}

int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2);

    return 0;
}
