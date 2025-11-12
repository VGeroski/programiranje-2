/* Zadatak 1:
 * Napisati program koji filtrira datoteku imena.txt tako sto na standardni izlaz 
 * ispisuje samo imena i prezimena. Maksimalna duzina imena, kao i prezimena je
 * 50 karaktera. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 51

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

int main()
{
    int rb;
    double prosek;
    char ime[MAX], prezime[MAX];

    FILE *f = fopen("imena.txt", "r");
    if (f == NULL)
        greska();

    /* Napomena: posle %d potrebno je . zbog rednog broja (pogledati imena.txt) */
    while (fscanf(f, "%d.%s%s%lf", &rb, ime, prezime, &prosek) == 4)
    {
        if (isupper(ime[0]) && isupper(prezime[0]))
            printf("%s %s\n", ime, prezime);
    }

    fclose(f);
    return 0;
}