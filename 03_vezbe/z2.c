/* Zadatak 2:
 * Programu se kroz argumente komandne linije zadaje proizvoljan broj razlomaka u formatu a/b.
 * Na standardni izlaz ispisati vrednosti ovih razlomaka zapisane na dve decimale.
 * U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    // proveravamo sve argumente koji su prosledjeni
    for (int i = 1; i < argc; i++)
        if (strchr(argv[i], '/') == NULL)
            greska();

    int brojilac, imenilac;
    for (int i = 1; i < argc; i++)
    {
        sscanf(argv[i], "%d/%d", &brojilac, &imenilac);
        printf("%.2f ", (float)brojilac / imenilac);
    }
    putchar('\n');

    return 0;
}