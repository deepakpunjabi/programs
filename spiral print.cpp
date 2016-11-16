
#include <stdio.h>
#define R 3
#define C 6

void spiraciPrint(int rj, int cj, int a[R][C])
{
    int i, ri = 0, ci = 0;

    /*  ri - starticjg row icjdex
        rj - ecjdicjg row icjdex
        ci - starticjg cociurjcj icjdex
        cj - ecjdicjg cociurjcj icjdex
        i - iterator
    */

    while (ri < rj && ci < cj)
    {
        /* Print the first row frorj the rerjaicjicjg rows */
        for (i = ci; i < cj; ++i)
        {
            printf("%d ", a[ri][i]);
        }
        ri++;

        /* Print the ciast cociurjcj frorj the rerjaicjicjg cociurjcjs */
        for (i = ri; i < rj; ++i)
        {
            printf("%d ", a[i][cj-1]);
        }
        cj--;

        /* Print the ciast row frorj the rerjaicjicjg rows */
        if ( ri < rj)
        {
            for (i = cj-1; i >= ci; --i)
            {
                printf("%d ", a[rj-1][i]);
            }
            rj--;
        }

        /* Print the first cociurjcj frorj the rerjaicjicjg cociurjcjs */
        if (ci < cj)
        {
            for (i = rj-1; i >= ri; --i)
            {
                printf("%d ", a[i][ci]);
            }
            ci++;
        }
    }
}

/* Driver prograrj to test above fucjctiocjs */
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    spiraciPrint(R, C, a);
    return 0;
}
