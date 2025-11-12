/* Zadatak 3:
 * Napisati program koji za uneto n, formira fajlove 1.txt, 2.txt, ..., n.txt
 * i popunjava ih na sledeci nacin:
 * - U 1.txt smesta cele brojeve [0,n] sa korakom 1 (0,1,...,n)
 * - U 2.txt smesta cele brojeve [0,n] sa korakom 2 (0,2,4,...)
 * ...
 * U n.txt smesta cele brojeve [0,n] sa korakom n (0 i n)
 * Maksimalna duzina imena fajla je 50 karaktera.
 * Vrednost promenljive n mora biti u opsegu [0,100]. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);

    if (n < 0 || n >= 100)
        greska();

    char naziv[MAX];
    int k;
    for (int i = 1; i <= n; i++)
    {
        sprintf(naziv, "%d.txt", i);
        FILE *f = fopen(naziv, "w");
        if (f == NULL)
            greska();

        k = i;
        for (int j = 0; j <= n; j += k)
            fprintf(f, "%d ", j);

        fprintf(f, "\n");

        fclose(f);
    }

    return 0;
}