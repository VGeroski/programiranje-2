/**
 * Napisati rekurzivnu funkciju int f3(int x) koja u početnom zapisu broja
 * x izbacuje svaku neparnu cifru, ukoliko se ispred te cifre nalazi cifra 2.
 * Napisati program koji testira ovu funkciju, tako što sa standardnog ulaza ucitava ceo broj x,
 * i na standardni izlaz ispisuje vrednost funkcije f3(x).
 * Napomena: Zadatak mora biti uradjen rekurzivno.
 *
 * ulaz: 325
 * izlaz: 32
 *
 * ulaz: 23523
 * izlaz: 252
 *
 * ulaz: 12345
 * izlaz: 1245
 */

#include <stdio.h>

/* 23523 -> 252 */
int f3(int x)
{
    if (x == 0)
        return 0;

    int poslednja = x % 10;
    int pretposlednja = (x / 10) % 10;

    int rez = f3(x / 10);

    if (poslednja % 2 != 0 && pretposlednja == 2)
        return rez;

    return rez * 10 + poslednja;
}

int main()
{
    printf("Broj nakon izbacivanja: %d\n", f3(325));
    printf("Broj nakon izbacivanja: %d\n", f3(23523));
    printf("Broj nakon izbacivanja: %d\n", f3(12345));

    return 0;
}