#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main()
{
    char ime[MAX], prva_rec[MAX], rec[MAX];
    scanf("%s", ime);

    FILE *ulaz = fopen(ime, "r");
    if (ulaz == NULL)
        greska();

    FILE *rez = fopen("rez.txt", "w");
    if (rez == NULL)
        greska();

    int n; // broj reci
    fscanf(ulaz, "%d", &n);

    fscanf(ulaz, "%s", prva_rec);
    for (int i = 1; i < n; i++)
    {
        fscanf(ulaz, "%s", rec);

        if (strstr(rec, prva_rec) != NULL && strchr(rec, '_') != NULL)
            fprintf(rez, "%s ", rec);
    }

    fclose(ulaz);
    fclose(rez);
    return 0;
}
