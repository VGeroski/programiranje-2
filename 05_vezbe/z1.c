/**
 * Napisati rekurzivnu funkciju koja prikazuje sve cifre datog celog pozitivnog broja i to:
 *  - void ispis1(int x): koja ispisuje s leva na desno
 *  - void ispis2(int x): koja ispisuje s desna na levo
 * 
 * Primer
 * a) 34021 -> 3 4 0 2 1
 * b) 56219 -> 9 1 2 6 5
 */

#include <stdio.h>

/* glavni zadatak je izdvajanje cifara */
/* 34819 --> 3481 --> 348 --> 34 --> 3 --> 0*/
void ispis1(int broj)
{
    if (broj == 0)
        return;
    else
    {
        ispis1(broj / 10);

        int cifra = broj % 10;
        printf("%d ", cifra);
    }
}

void ispis2(int broj)
{
    if (broj == 0)
        return;
    else
    {
        int cifra = broj % 10;
        printf("%d ", cifra);

        ispis2(broj / 10);
    }
}

int main()
{
    ispis1(34819);
    putchar('\n');
    ispis2(56219);

    return 0;
}