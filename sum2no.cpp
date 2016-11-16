#include <iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    while(n2)
    {
        int carry = n1 & n2;
        n1 = n1 ^ n2;
        cout<<n1<<"\t";
        n2 = carry << 1;
        cout<<n2<<endl;
    }
    cout<<n1<<endl;
}