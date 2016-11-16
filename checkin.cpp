#include<iostream>

using namespace std;

inline void swapi(int *a,int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
    swapi(b,a);
}
int main(){
    int a=5,b=6;
    swapi(&a,&b);
    return 0;
}
