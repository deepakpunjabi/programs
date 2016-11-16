#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i;
    vector<int> look(100);
    look[0]=look[1]=1;

    cin>>i;

    for(int j=2;j<=i;j++)   look[j]=look[j-1]+look[j-2];

    cout<<look[i]<<endl;
    return 0;
}