/**
 * Napisati rekurzivnu funkciju void napravi_niz(int *kraj_niza, int broj) koja
 * kreira niz cifara datog celog broja. Napisati rekurzivnu funkciju void ispis_niz(int *niz, int n)
 * koja ispisuje elemente niza duzine n. Testirati obe funkcije pozivom iz glavnog programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DUZINA 11

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int broj_cifara(int broj)
{
    if (broj == 0)
        return 0;

    int rez = broj_cifara(broj / 10);
    return rez + 1;
}

/* 3451 -> niz: 3 4 5 1 */
void napravi_niz(int *kraj_niza, int broj)
{
    if (broj < 10)
    {
        *kraj_niza = broj;
        return;
    }

    int poslednja = broj % 10;
    *kraj_niza = poslednja;

    napravi_niz(kraj_niza - 1, broj / 10);
}

int *napravi_niz_v2(int *niz, int broj)
{
    if (broj < 10)
    {
        *niz = broj;
        return niz + 1;
    }

    int *kraj_niza = napravi_niz_v2(niz, broj / 10); /* ovde kraj niza pokazuje van niza */
    *kraj_niza = broj % 10;                          /* koristimo da popunimo sa poslednjom cifrom */
    return kraj_niza + 1;
}

void ispis_niza(int *niz, int n)
{
    if (n == 0)
        return;

    // printf("%d ", niz[0]);
    // ispis_niza(niz + 1, n - 1);

    ispis_niza(niz, n - 1);
    printf("%d ", niz[n - 1]);
}

int main()
{
    int *niz = NULL;

    int broj = 3451;
    // int n = broj_cifara(broj);

    niz = malloc(DUZINA * sizeof(int));
    if (niz == NULL)
        greska();

    /* printf("%d\n", INT_MAX); zakljucujemo da int moze najvise da ima 10 cifara */

    /* moramo da pazimo da prosledimo pokazivac na poslednji element */
    /* napravi_niz(niz + (n - 1), broj); */

    int *kraj_niza = napravi_niz_v2(niz, broj);
    int n = kraj_niza - niz;

    ispis_niza(niz, n);

    free(niz);
    return 0;
}