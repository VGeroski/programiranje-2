/**
 * Napisati rekurzivnu funkciju int broj_parnih(int x) koja
 * racuna broj parnih cifara datog celog broja x.
 */

#include <stdio.h>

/**
 * Prvi slucaj:
 * 34821
 * Drugi slucaj:
 * 34826
 */
int broj_parnih(int x)
{
    if (x == 0)
        return 0;
    else
    {
        int broj = broj_parnih(x / 10); // 3482 broj = 3
        /* I slucaj: return broj;
         * II slucaj: return broj + 1; zato sto je zadnja cifra parna */
        int cifra = x % 10;
        if (cifra % 2 != 0)
            return broj;
        else
            return broj + 1;
    }
}

int main()
{
    printf("Broj parnih %d\n", broj_parnih(34821));
    printf("Broj parnih %d\n", broj_parnih(34826));

    return 0;
}