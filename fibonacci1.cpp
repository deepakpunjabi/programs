#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int fib(int n, vector<int>& lookup)
{
    if (lookup[n] == -1)
    {
        lookup[n] = fib(n-1,lookup) + fib(n-2,lookup);
    }
    return lookup[n];
}

int main()
{
    vector<int> lookup(MAX, -1);
    lookup[0] = lookup[1] = 1;

    int n;
    cin >> n;
    
    cout << fib(n, lookup)<<endl;
    for(int i=0;i<=n;i++) cout<<lookup[i];

    return 0;
}