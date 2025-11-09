/* Zadatak 3:
 * Napisati program koji ucitava niz celih brojeva iz datoteke brojevi.txt sve do unosa broja 0,
 * Koristeci funkciju za realokaciju memorije sa korakom k (koji se zadaje kao argument komandne linije).
 * Na std izlaz ispisati sve brojeve koji su veci od sredisnjeg elementa niza. U slucaju parne dimenzije niza,
 * sredisnji element racunati kao aritmeticku sredinu dva elementa najbliza sredini. 
 * U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        greska();

    int k = atoi(argv[1]);

    int *niz = malloc(k * sizeof(int));
    if (niz == NULL)
        greska();

    int alocirano = k; /* koliko je do sad alocirano memorije */

    FILE *f = fopen("brojevi.txt", "r");
    if (f == NULL)
        greska();

    int i = 0;
    int x;
    while (1)
    {
        /* proveravamo da li je potrebna re-alokacija memorije */
        if (i == alocirano)
        {
            alocirano += k;
            niz = realloc(niz, alocirano * sizeof(int));
            if (niz == NULL)
                greska();
        }

        fscanf(f, "%d", &x);
        if (x == 0)
            break;

        niz[i] = x;
        i++;
    }

    /* broj stvarno koliko niz ima elemenata */
    int n = i;

    double sredina;
    if (n % 2 == 1)
        sredina = (double)niz[n / 2];
    else
        sredina = ((double)niz[n / 2 - 1] + niz[n / 2]) / 2;

    for (int i = 0; i < n; i++)
        if (niz[i] > sredina)
            printf("%d ", niz[i]);

    fclose(f);
    free(niz);
    niz = NULL;

    return 0;
}