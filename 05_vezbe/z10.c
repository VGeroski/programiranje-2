/**
 * Napisati rekurzivnu funkciju int dodaj_0(int x) koja
 * posle svake neparne cifrte datog broja dodaje 0
 */

#include <stdio.h>

/* x = 2343 -> 230430 */
int dodaj_0(int x)
{
    if (x == 0)
        return 0;

    int rez = dodaj_0(x / 10); /* 234 -> 2304 */
    int poslednja = x % 10;
    if (poslednja % 2 != 0) /* 2304*100 + poslednja * 10 */
        return rez * 100 + poslednja * 10;

    /* ako je parna poslednja, samo dodamo tu cifru na kraj */
    return rez * 10 + poslednja;
}

int main()
{
    printf("Broj nakon dodavanja 0: %d\n", dodaj_0(2343));
    printf("Broj nakon dodavanja 0: %d\n", dodaj_0(23436));
    printf("Broj nakon dodavanja 0: %d\n", dodaj_0(33436));

    return 0;
}