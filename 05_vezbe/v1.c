/**
 * Zadatak 1:
 * prvi deo: Ispisati brojeve od 1 do n.
 * drugi deo: Ispisati brojeve od n do 1.
 * treci deo: Ispisati brojeve od n - 1, korak 2 (svaki drugi)
 */

#include <stdio.h>

void ispis_v1(int n)
{
    /* kod rekurzije treba da svedemo problem na manju dimenziju u rekurzivnom koraku */

    if (n == 1)
        printf("1 ");
    else
    {
        /* ispis brojeva od 1 do n - 1 -> manja dimenzija */
        ispis_v1(n - 1);
        printf("%d ", n);
    }
}

/* Druga verzija ispisa brojeva od 1 do n */
void ispis_v2(int n)
{
    if (n == 0)
        return;

    ispis_v2(n - 1);
    printf("%d ", n);
}

/* drugi deo -- Ispis brojeva od n do 1 */
void ispis_v3(int n)
{
    if (n == 0)
        return;

    printf("%d ", n);
    ispis_v3(n - 1);
}

void ispis_svaki_drugi(int n)
{
    if (n <= 0)
        return;
    else
    {
        printf("%d ", n);
        ispis_svaki_drugi(n - 2);
    }
}

int main()
{
    ispis_v1(10);
    putchar('\n');
    ispis_v2(10);
    putchar('\n');

    ispis_v3(10);
    putchar('\n');

    ispis_svaki_drugi(11);
    putchar('\n');

    return 0;
}