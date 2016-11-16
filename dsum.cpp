#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n,sum1=0,sum2=0,sum;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
           if(a_i==a_j){
               sum1+=a[a_i][a_j];
               cout<<"added in sum1"<<a[a_i][a_j];
           }
           else if(a_i+a_j==n-1){
               sum2+=a[a_i][a_j];
           }
       }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] <<endl;
        }

    }
    cout << "sum1 " << sum1;
    cout<<"sum2"<<sum2;
    cout << "difference";
    sum = abs(sum1-sum2);
    cout << sum;
    return 0;
}
