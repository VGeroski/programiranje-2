/**
 * Napisati rekurzivnu funkciju void obrni_niz(int *a, int n) koja
 * obrce niz brojeva (niz alocirati dinamicki).
 */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

/* [1 2 3 4 5 6] -> [6 5 4 3 2 1] */
/* [6 2 3 4 5 1] : prvi korak     */
/* [  5 3 4 2  ] : drugi korak    */
/* [    4 3    ] : treci korak    */
/* [           ]                  */
void obrni_niz(int *a, int n)
{
    if (n <= 1)
        return;

    int pomocna = a[n - 1];
    a[n - 1] = a[0];
    a[0] = pomocna;

    obrni_niz(a + 1, n - 2);
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

    obrni_niz(niz, n);

    ispis_niz(niz, n);

    return 0;
}