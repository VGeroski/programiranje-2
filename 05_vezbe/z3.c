/**
 * Napisati rekurzivnu funkciju int najveca_cifra(int x) koja
 * racuna najvecu cifru datog celog broja x.
 */

#include <stdio.h>

int najveca_cifra(int broj)
{
    if (broj < 10)
        /* zaustavljamo se kad stignemo do jedne cifre */
        return broj;
    else
    {
        int max_cifra = najveca_cifra(broj / 10); /* maksimalna cifra do poslednje cifre */
        /* ostaje da poredimo samo jos sa poslednjom cifrom */
        int trenutna_cifra = broj % 10;
        return (trenutna_cifra > max_cifra ? trenutna_cifra : max_cifra);
    }
}

int main()
{
    printf("Najveca cifra %d\n", najveca_cifra(23451));

    return 0;
}