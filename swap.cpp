#include<stdio.h>

int main(){
    int x =5, y=5;
    int *p,*q;
    p = &x;
    q = &x;

    x = x xor y;
    y = x xor y;
    x = x xor y;

    printf("x=%d y=%d\n",x,y);

    x = x xor x;
    x = x xor x;
    x = x xor x;

    printf("x=%d y=%d\n",x,x);


    *p = *p xor *q;
    *q = *p xor *q;
    *p = *p xor *q;

    printf("x=%d y=%d",*p,*q);

}
