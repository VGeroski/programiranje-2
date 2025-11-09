/* Zadatak 6:
 * Definisati strukturu
 * typedef struct{
 *   unsigned int a, b;
 *   char ime[5];
 * } PRAVOUGAONIK;
 *  kojom se opisuje pravougaonik duzinama svojih stranica i imenom.
 * Napisati program koji iz datoteke cije ime se zadaje kao argument komandne linije ucitava pravougaonike
 * a zatim prvo ispisuje imena onih pravougaonika koji su kvadrati,
 * a nakon toga ispisuje vrednost najvece povrsine medju pravougaonicima koji nisu kvadrati.
 * U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int a, b;
    char ime[5];
} PRAVOUGAONIK;

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        greska();

    PRAVOUGAONIK *niz = NULL;

    int k = 5;
    niz = malloc(k * sizeof(PRAVOUGAONIK));
    if (niz == NULL)
        greska();

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        greska();

    unsigned int a, b;
    char ime[5];
    int ucitano = 0, alocirano = k;
    while (fscanf(f, "%u%u%s", &a, &b, ime) == 3)
    {
        if (ucitano == alocirano)
        {
            alocirano += k;
            niz = realloc(niz, alocirano * sizeof(PRAVOUGAONIK));
            if (niz == NULL)
            {
                free(niz);
                greska();
            }
        }

        niz[ucitano].a = a;
        niz[ucitano].b = b;
        strcpy(niz[ucitano].ime, ime);
        ucitano++;
    }

    int n = ucitano;

    for (int i = 0; i < n; i++)
    {
        if (niz[i].a == niz[i].b)
            printf("%s",niz[i].ime);
    }

    unsigned int max_p = 0;
    for (int i = 0; i < n; i++)
    {
        if (niz[i].a != niz[i].b && niz[i].a * niz[i].b > max_p)
            max_p = niz[i].a * niz[i].b;
    }
    printf(" %d\n", max_p);
        
    fclose(f);
    free(niz);

    return 0;
}