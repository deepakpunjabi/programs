#include <iostream>
using namespace std;

void change(int &a){
    a[2]=9;
}

int main(){
    int a[]={1,2,3,4,5};
    change(a);

    for(int i:a) cout<<*a<<endl;
    
    return 0;
}