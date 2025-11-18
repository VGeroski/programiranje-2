#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

// hocemo da u klijentskom delu da odmah znamo koliki je stepen polinoma
// zato koristimo *n, a vracamo kreirani niz
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
    // n je stepen polinoma, a ne duzina niza

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

// prosledjujemo **c jer hocemo da promenimo pokazivac u main na sta pokazuje
// ne samo kopija pokazivaca da se preusmeri, nego bas pokazivac iz main-a
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

int main()
{

    int n, m;
    int *p1 = unos(&n);
    int *p2 = unos(&m);

    // ispis_polinoma(p1, n);
    // ispis_polinoma(p2, m);

    int *c;
    int suma = suma_polinoma(p1, n, p2, m, &c);

    ispis_polinoma(c, suma);

    free(p1);
    free(p2);
    free(c);

    return 0;
}
