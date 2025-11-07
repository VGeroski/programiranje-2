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
    FILE *ulaz = fopen("knjiga.txt", "r");
    if (ulaz == NULL)
        greska();

    int brojac = 0;
    char c;
    // Prvi nacin - brojanje '/n' karaktera da bi odredili broj linija
    // while (fscanf(ulaz, "%c", &c) != EOF)
    // {
    //     if (c == '\n')
    //         brojac++;
    // }
    // Kada je naisao EOF nije uracunao jos jedan novi red
    // brojac++;

    char linija[MAX];
    while (fgets(linija, MAX, ulaz) != NULL)
        brojac++;

    printf("%d\n", brojac);

    fclose(ulaz);
    return 0;
}