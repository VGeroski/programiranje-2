/**
 * Zadatak 2:
 * - Izracunati sumu od 1 do n
 * - Izracunati proizvod od 1 do n
 */

#include <stdio.h>

int suma(int n)
{
    if (n == 1)
        return 1;
    else
    {
        int broj = suma(n - 1); // broj = 1 + 2 + 3 + ... + n - 1
        return broj + n;
    }
}

int suma_v2(int n)
{
    if (n == 1)
        return 1;
    else
        return suma(n - 1) + n;
}

int proizvod(int n)
{
    if (n == 1)
        return 1;
    else
        return proizvod(n - 1) * n;
}

int main()
{
    printf("Suma od 1 do 5 je %d\n", suma(5));
    printf("Suma (v2) od 1 do 5 je %d\n", suma_v2(5));
    printf("Proizvod brojeva od 1 do 5 je %d\n", proizvod(5));
    return 0;
}