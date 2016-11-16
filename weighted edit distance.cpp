//number string
//
//You are given two number-strings A and B. A number-string is a string that contains only digits ['0'-'9'].
//
//The task is to make both the strings equal. The only operation that you are allowed to do is to delete a character (i.e. digit) from any of the strings (A or B).
//
//The cost of an operation of deleting a digit D is D units.
//Now, you have to make both the number-strings equal in minimum cost.
//
//Constraints:
//1 <= T <= 10
//1 <= length(A),length(B) <= 1000
//
//Input Format:
//First line of each testfile contains T, the number of test cases.
//In each testcase, first line contains number-string A and second line contains number-string B.
//
//Output Format:
//For each test case, output only line containing the minimum cost to make both number-strings equal.
//
//Example:
//
//Input:
//3
//7135
//135
//816337897
//816393804
//816337597
//816393504
//
//Output:
//7
//36
//34

#include<bits/stdc++.h>
using namespace std;

int wlcs(string x,string y){
    int m=x.length();
    int n=y.length();
    int mat[m+1][n+1];
    int sum=0;

    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 && j==0){
                mat[0][0]=0;
            }
            else if(i==0 && j!=0){
                mat[i][j]=mat[i][j-1]+y[j-1]-'0';
            }
            else if(j==0 && i!=0){
                mat[i][j]=mat[i-1][j]+x[i-1]-'0';
            }
            else if(x[i-1]==y[j-1]){
                mat[i][j]=mat[i-1][j-1];
            }
            else{
                mat[i][j]=min(mat[i-1][j]+x[i-1]-'0',mat[i][j-1]+y[j-1]-'0');
            }
        }
    }
    return mat[m][n];
}

/* Driver program to test above function */
int main()
{
  int t;
  cin>>t;

  while(t--){
    string x,y;
    cin>>x;
    cin>>y;
    cout<<wlcs(x,y);
  }

  return 0;
}
