/**
 * Napisati rekurzivnu funkciju int ukloni(int x, int cifra) koja uklanja
 * sva pojavljivanja date cifre c iz datog broja x
 */

#include <stdio.h>

int ukloni(int broj, int cifra)
{
    if (broj == 0)
        return 0;

    int rez = ukloni(broj / 10, cifra); /* 322782323 -> 3783 */
    /* I slucaj - vreacamo samo rez
     * II slucaj - ako na kraju nije 'cifra' onda vracamo rez i tu cifru */
    int poslednja = broj % 10;
    if (poslednja == cifra)
        return rez;
    else
        return rez * 10 + poslednja;
}

int main()
{
    /* 32278232 -> 3783 (nakon uklanjanja treba da bude) */
    printf("Ociscene cifre (cifra na kraju): %d\n", ukloni(322782322, 2));
    printf("Ociscene cifre: %d\n", ukloni(322782325, 2));

    return 0;
}
