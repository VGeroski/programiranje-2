#include <stdio.h>
#include <stdlib.h>

#define MAX 81 /* 80 karaktera + terminalna nula */

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    FILE *ulaz = fopen("ulaz.txt", "r");
    if (ulaz == NULL)
        greska();

    FILE *izlaz = fopen("izlaz.txt", "w");
    if (izlaz == NULL)
        greska();

    /* prva verzija: raditi karakter po karakter */
    // char c;

    /* verizja preko fscanf sa formatom %c - karakter po karakter */
    // while (fscanf(ulaz, "%c", &c) != EOF)
    //     fprintf(izlaz, "%c", c);

    /* verizja preko fgetc - karakter po karakter */
    // while ((c = fgetc(ulaz)) != EOF)
    //     fputc(c, izlaz);

    /* druga verzija: raditi liniju po liniju */
    char linija[MAX];
    while (fgets(linija, MAX, ulaz) != NULL)
        fprintf(izlaz, "%s", linija);

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}