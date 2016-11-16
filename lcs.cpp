#include<bits/stdc++.h>
using namespace std;
int lcs(char x[],char y[],int m,int n){
    int mat[m+1][n+1];

    for(int i=0;i<n+1;i++)  mat[0][i]=0;
    for(int i=0;i<m+1;i++)  mat[i][0]=0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    return mat[m][n];
}

/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  return 0;
}
