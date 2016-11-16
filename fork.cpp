#include<iostream>
#include<cstdlib>
#include<unistd.h>

using namespace std;

int main(){
    int a=5;
    int pid = fork();
    if(pid==0){
        int b=2;
        double c=6;
        cout<<"a "<<&a<<"\t"<<a<<endl;
        cout<<"c "<<&c<<"\t"<<c<<endl;
    }
    else{
        a=10;
        int c=10;
        cout<<"c "<<&c<<"\t"<<c<<endl;
        cout<<"a "<<&a<<"\t"<<a<<endl;

    }
    return 0;
}
