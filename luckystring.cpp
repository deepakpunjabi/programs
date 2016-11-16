
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t, l, j, k, s, sf, i;
    char a[1005], b[1005], c[1005];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", a);
        l = strlen(a);
        if (l < 9)
        {
            printf("unlucky\n");
            continue;
        }
        s = sf = 0;
        for (j = 0; j < l - 4; j++)
        {
            if (((l - (2 * j)) > 9) || ((l - (2 * j)) < 1) || (((l / 2) == j + 4) && (l % 2 != 0)) || (((l / 2) == j) && (l % 2 != 0)))
            {
                if (j == 0)
                {
                    s = 0;
                    for (k = 0; k < l; k++)
                        b[k] = a[k];
                    if (b[j] != 'l')
                    {
                        s++;
                        b[j] = 'l';
                    }
                    if (b[l - 1 - j] != 'l')
                    {
                        s++;
                        b[l - 1 - j] = 'l';
                    }
                    if (b[j + 1] != 'u')
                    {
                        s++;
                        b[j + 1] = 'u';
                    }
                    if (b[l - j - 2] != 'u')
                    {
                        s++;
                        b[l - j - 2] = 'u';
                    }
                    if (b[j + 2] != 'c')
                    {
                        s++;
                        b[j + 2] = 'c';
                    }
                    if (b[l - j - 3] != 'c')
                    {
                        s++;
                        b[l - j - 3] = 'c';
                    }
                    if (b[j + 3] != 'k')
                    {
                        s++;
                        b[j + 3] = 'k';
                    }
                    if (b[l - j - 4] != 'k')
                    {
                        s++;
                        b[l - j - 4] = 'k';
                    }
                    if (b[j + 4] != 'y')
                    {
                        s++;
                        b[j + 4] = 'y';
                    }
                    if (b[l - j - 5] != 'y')
                    {
                        s++;
                        b[l - j - 5] = 'y';
                    }
                    for (k = 0; k <= l / 2; k++)
                    {
                        if (b[k] != b[l - k - 1])
                        {
                            s++;
                            if (b[k] > b[l - k - 1])
                                b[k] = b[l - k - 1];
                            else
                                b[l - k - 1] = b[k];
                        }
                    }
                    sf = s;
                    continue;
                }
                s = 0;
                for (k = 0; k < l; k++)
                    c[k] = a[k];
                if (c[j] != 'l')
                {
                    s++;
                    c[j] = 'l';
                }
                if (c[l - 1 - j] != 'l')
                {
                    s++;
                    c[l - 1 - j] = 'l';
                }
                if (c[j + 1] != 'u')
                {
                    s++;
                    c[j + 1] = 'u';
                }
                if (c[l - j - 2] != 'u')
                {
                    s++;
                    c[l - j - 2] = 'u';
                }
                if (c[j + 2] != 'c')
                {
                    s++;
                    c[j + 2] = 'c';
                }
                if (c[l - j - 3] != 'c')
                {
                    s++;
                    c[l - j - 3] = 'c';
                }
                if (c[j + 3] != 'k')
                {
                    s++;
                    c[j + 3] = 'k';
                }
                if (c[l - j - 4] != 'k')
                {
                    s++;
                    c[l - j - 4] = 'k';
                }
                if (c[j + 4] != 'y')
                {
                    s++;
                    c[j + 4] = 'y';
                }
                if (c[l - j - 5] != 'y')
                {
                    s++;
                    c[l - j - 5] = 'y';
                }
                for (k = 0; k <= l / 2; k++)
                {
                    if (c[k] != c[l - k - 1])
                    {
                        s++;
                        if (c[k] > c[l - k - 1])
                            c[k] = c[l - k - 1];
                        else
                            c[l - k - 1] = c[k];
                    }
                }
                if (s < sf)
                {
                    for (i = 0; i < l; i++)
                        b[i] = c[i];
                    sf = s;
                    continue;
                }
                if (s > sf)
                    continue;
                for (i = 0; i < l; i++)
                {
                    if (c[i] > b[i])
                        break;
                    if (c[i] < b[i])
                    {
                        sf = s;
                        for (k = 0; k < l; k++)
                            b[k] = c[k];
                        break;
                    }
                }
            }
        }
        for (k = 0; k < l; k++)
            printf("%c", b[k]);
        printf(" %d\n", sf);
    }
}