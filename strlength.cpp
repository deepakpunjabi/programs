#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    char *s="hello";

    cout<<sizeof(void*)<<endl;
    cout<<strlen(s)<<endl<<sizeof(s);
    return 0;
}
