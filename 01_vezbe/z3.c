#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    char opcija, c;
    char ulaz_ime[MAX], izlaz_ime[MAX];

    printf("Unesite imena datoteka za ulaz i izlaz i opciju: ");
    scanf("%s %s %c", ulaz_ime, izlaz_ime, &opcija);

    FILE *ulaz = fopen(ulaz_ime, "r");
    if (ulaz == NULL)
        greska();

    FILE *izlaz = fopen(izlaz_ime, "w");
    if (izlaz == NULL)
        greska();

    while((c = fgetc(ulaz)) != EOF)
    {
        if (opcija == 'u')
        {
            c = toupper(c);
            fputc(c, izlaz);
        }
        else
        {
            c = tolower(c);
            fputc(c, izlaz);
        }
    }

    fclose(ulaz);
    fclose(izlaz);
    return 0;
}