/* Zadatak 2:
 * Napisati program koji sa standardnog ulaza ucitava niz razlomaka.
 * Prvo se ucita broj razlomaka, a zatim i razlomci u obliku brojilac imenilac.
 * Na std izlaz ispisati sve razlomke cija je vrednost veca od prosescne vrednosti
 * svih ucitanih razlomaka, u obliku brojilac/imenilac.
 * Ne praviti pretpostavke o dimenziji niza. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    int n;
    int *br, *im;

    scanf("%d", &n);
    if (n < 0)
        greska();

    br = malloc(n * sizeof(int));
    if (br == NULL)
        greska();

    im = malloc(n * sizeof(int));
    if (im == NULL)
        greska();

    int x, y;
    double suma = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        if (y == 0)
            greska();

        suma += ((double)x / y);
        br[i] = x;
        im[i] = y;
    }

    double prosek = suma / n;

    for (int i = 0; i < n; i++)
    {
        if ((double)br[i] / im[i] > prosek)
            printf("%d/%d", br[i], im[i]);
    }

    free(br);
    br = NULL;

    free(im);
    im = NULL;

    return 0;
}