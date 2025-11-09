/* Zadatak 1:
 * Napisati program koji sa standardnog ulaza ucitava dimenziju niza celih brojeva,
 * a zatim i njegove elemente. Ne praviti pretpostavke o dimenziji niza.
 * Ispisati ucitane brojeve u obrnutom poretku. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    // ucitavanje dimenizije niza
    int n;
    scanf("%d", &n);
    if (n < 0)
        greska();

    int *niz = malloc(sizeof(n * sizeof(int)));
    if (niz == NULL)
        greska();

    for (int i = 0; i < n; scanf("%d", &niz[i++]))
        ;

    for (int i = n - 1; i >= 0; printf("%d ", niz[i--]))
        ;
    putchar('\n');

    free(niz);
    niz = NULL;

    return 0;
}