#include <stdio.h>
int main()
{
    char *s = "1234567";
    int *i;
    printf("%s",s);
//    s[3]='c';
    printf("%lu %lu", sizeof(char),sizeof(int));


    // Uncommenting below line would cause undefined behaviour
    // (Caused segmentation fault on gcc)
    //  s[0] = 'j';
    return 0;
}
