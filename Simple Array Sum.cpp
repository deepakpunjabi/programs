//Given an array of N integers, can you find the sum of its elements?
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <numeric>
using namespace std;
int main(){
    int count,n,sum=0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       sum+=arr[arr_i];
    }
    //method 2
    //sum = accumulate(arr.begin(),arr.end(),0);
        
    cout << sum;
    return 0;
}