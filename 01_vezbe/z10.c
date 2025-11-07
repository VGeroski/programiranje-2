#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        greska();

    FILE *f1 = fopen(argv[1], "r");
    if (f1 == NULL)
        greska();

    FILE *f2 = fopen(argv[2], "r");
    if (f2 == NULL)
        greska();

    int brojac = 1;
    char l1[MAX], l2[MAX];
    // uzimamo liniju po liniju i poredimo
    while (fgets(l1, MAX, f1) != NULL && fgets(l2, MAX, f2) != NULL)
    {
        // ispisujemo samo ako se razlikuju dve linije
        if (strcmp(l1, l2) != 0)
            printf("%d\n", brojac);
        brojac++;
    }

    while (fgets(l1, MAX, f1) != NULL)
    {
        printf("%d\n", brojac);
        brojac++;
    }

    while (fgets(l2, MAX, f2) != NULL)
    {
        printf("%d\n", brojac);
        brojac++;
    }
    
    fclose(f1);
    fclose(f2);

    return 0;
}