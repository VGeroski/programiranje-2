/**
 * Napisati rekurzivnu funkciju int palindrom(int *a, int n) koja
 * ispituje da li su elementi nekog niza brojeva poredjani palindromski
 * (isto od napred i od pozadi)
 */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

/* [1 2 3 4 4 2 1] -> 0 (nije palindrom)                               */
/* [1 2 3 4 4 2 1] : prvi korak (uporedjujemo prvi i krajnji element)  */
/* [  2 3 4 4 2  ] : drugi korak                                       */
/* [    3 4 4    ] : treci korak (3 != 4 -> vracamo da nije palindrom) */
int palindrom(int *a, int n)
{
    if (n <= 1)
        return 1;

    if (a[0] != a[n - 1])
        return 0;

    palindrom(a + 1, n - 2);
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

    int x = palindrom(niz, n);
    if (x)
        printf("Niz je palindrom.\n");
    else
        printf("Niz NIJE palindrom.\n");

    ispis_niz(niz, n);

    return 0;
}