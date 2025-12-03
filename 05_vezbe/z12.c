/**
 * Napisati rekurzivnu funkciju koja ispisuje
 *     *
 *    **
 *   ***
 *  ****
 * *****
 */

#include <stdio.h>

void ispisi_trougao(int n, int trenutna_linija)
{
    if (trenutna_linija > n)
        return;

    /* ispisujemo celu liniju */
    for (int i = 0; i < n; i++)
        if (i >= (n - trenutna_linija))
            printf("*");
        else
            printf(" ");
    printf("\n");

    ispisi_trougao(n, trenutna_linija + 1);
}

int main()
{
    ispisi_trougao(5, 1);

    return 0;
}