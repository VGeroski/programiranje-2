/**
 * Sa standardnog ulaza se ucitava ceo broj x, ceo broj n (n <= 100), a potom i niz od
 * n celih brojeva. Napisati rekurzivnu funkciju void f(int a[], int n, int x), koja
 * u nizu a poslavlja na nulu sve parove susednih elementa ciji je zbir
 * (u pocetnom nizu) jednak x. Rezultujući niz ispisati na standardni izlaz.
 * Zadatak mora biti uradjen rekurzivno.
 *
 * ulaz: 2 1 2 6 7 0 3 1 2 1, x = 3
 * izlaz: 0 0 0 6 7 0 0 0 0 0
 */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void f(int *a, int n, int x)
{
    if (n == 0)
        return;

    int prvi = a[0];
    int drugi = a[1];

    f(a + 1, n - 1, x);

    if (prvi + drugi == x)
    {
        a[0] = 0;
        a[1] = 0;
    }
}

void ispis_niz(int *niz, int n)
{
    if (n == 0)
        return;

    ispis_niz(niz, n - 1);
    printf("%d ", niz[n - 1]);
}

int main()
{
    int *niz = NULL;
    int n;

    printf("Unesi broj elemenata niza: ");
    scanf("%d", &n);
    if (n <= 0)
        greska();

    niz = malloc(n * sizeof(int));
    if (niz == NULL)
        greska();

    printf("Unesi elemente niza: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    f(niz, n, 3);

    ispis_niz(niz, n);

    return 0;
}
