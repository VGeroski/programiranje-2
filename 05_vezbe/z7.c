/**
 * Napisati rekurzivnu funkciju int obrni(int x, int p) koja obrce cifre datog celog broja x.
 */

#include <stdio.h>
#include <math.h>

int broj_cifara(int broj)
{
    if (broj == 0)
        return 0;

    int rez = broj_cifara(broj / 10);
    return rez + 1;
}

/* 27856 -> 65872 */
int obrni(int x, int p)
{
    if (x < 10)
        return x;

    int rez = obrni(x / 10, p - 1);
    int poslednja = x % 10;

    return poslednja * pow(10, p) + rez;
}

/* Promenljiva kontejner nam sluzi da akumulira resenja */
/* Na kraju, kontejner je zapravo resenje               */
/* x = 2345  kontejner = 0                              */
/* x = 234   kontejner = 5                              */
/* x = 23    kontejner = 54   => 5*10 + 4               */
/* x = 2     kontejner = 543  => 54*10 + 3              */
/* x = 0     kontejner = 5432 => 543*10 + 2             */
int obrni_v2(int x, int kontejner)
{
    if (x == 0)
        return kontejner;

    int novi_kontejner = kontejner * 10 + x % 10;
    obrni_v2(x / 10, novi_kontejner);
}

int main()
{
    int broj = 27856;
    int n = broj_cifara(broj);

    printf("Obrnuti broj: %d\n", obrni(broj, n - 1));
    printf("Obrnuti broj (v2): %d\n", obrni_v2(broj, 0));

    return 0;
}