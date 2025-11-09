/* Zadatak 5: 
 * Sa standardnog ulaza se ucitava rec pretrage, dimenzija niza, a zatim i niz reci. 
 * Pretpostavljati da je maksimalna duzina reci 20 karaktera. Na standardni izlaz ispisati
 * indeks prvog i poslednjeg pojavljivanja trazene reci u okviru unetog niza reci. 
 * U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    char *trazena;
    char **niz_reci;

    // standard je jedino da je bajt 1
    trazena = malloc(MAX);
    if (trazena == NULL)
        greska();

    scanf("%s", trazena);

    int n;
    scanf("%d", &n);
    niz_reci = malloc(n * sizeof(char *));
    if (niz_reci == NULL)
        greska();

    for (int i = 0; i < n; i++)
    {
        niz_reci[i] = malloc(MAX);
        if (niz_reci[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(niz_reci[j]);
            free(niz_reci);

            greska();
        }
    }

    for (int i = 0; i < n; i++)
        scanf("%s", niz_reci[i]);

    int prvo = -1, poslednji = -1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(niz_reci[i], trazena) == 0)
        {
            if (prvo == -1)
                prvo = i;

            poslednji = i;
        }
    }

    printf("%d %d\n", prvo, poslednji);

    free(trazena);

    for (int i = 0; i < n; i++)
        free(niz_reci[i]);
    free(niz_reci);
    return 0;
}