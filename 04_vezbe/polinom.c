#include "polinom.h"

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

int *unos(int *n)
{
    scanf("%d", n);

    int *koef = malloc((*n + 1) * sizeof(int));
    if (koef == NULL)
        greska();

    for (int i = 0; i <= *n; i++)
        scanf("%d", &koef[i]);

    return koef;
}

void ispis_polinoma(int *a, int n)
{
    if (n == 0)
    {
        printf("%d\n", a[0]);
        return;
    }

    if (a[1] != 0)
        printf("%d %c %d*x", a[0], a[1] > 0 ? '+' : '-', a[1]);

    for (int i = 2; i <= n; i++)
    {
        if (a[i] != 0)
            printf("%c %d*x^%d", a[i] > 0 ? '+' : '-', a[i], i);
    }
    putchar('\n');
}

int suma_polinoma(int *a, int n, int *b, int m, int **c)
{
    int r;

    if (n > m)
        r = n;
    else
        r = m;

    int *rez = malloc((r + 1) * sizeof(int));
    if (rez == NULL)
        greska();

    int i = 0;
    while (i <= n && i <= m)
    {
        rez[i] = a[i] + b[i];
        i++;
    }

    // sad je moguce da je ostalo jos polinoma u prvom ili drugom
    while (i <= n)
    {
        rez[i] = a[i];
        i++;
    }

    while (i <= m)
    {
        rez[i] = b[i];
        i++;
    }

    *c = rez;

    return r;
}

void mnoz_skalar(int *a, int n, int c)
{
    for (int i = 0; i <= n; i++)
        a[i] *= c;
}

int vr_poly(int *a, int n, int x)
{
    int rez = 0;

    for (int i = n; i >= 0; i--)
        rez = rez * x + a[i];

    return rez;
}

int mul_poly(int *a, int n, int *b, int m, int **c)
{
    int *rez = calloc(n + m + 1, sizeof(int));
    if (rez == NULL)
        greska();

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            rez[i + j] += a[i] * b[j];

    *c = rez;
    return m + n;
}