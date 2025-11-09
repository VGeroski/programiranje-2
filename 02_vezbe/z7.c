#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

typedef struct
{
    char puno_ime[MAX];
    int *ocene;
    int broj_ocena;
    double prosek;
} STUDENT;

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int najveci_prosek(STUDENT *niz, int n)
{
    double max_prosek = niz[0].prosek;
    int max_prosek_indeks = 0;
    for (int i = 1; i < n; i++)
        if (niz[i].prosek > max_prosek)
        {
            max_prosek = niz[i].prosek;
            max_prosek_indeks = i;
        }

    return max_prosek_indeks;
}

void ispisi(const STUDENT *s)
{
    printf("%s %.2lf\n", s->puno_ime, s->prosek);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        greska();

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        greska();

    STUDENT *niz = NULL;

    int n;
    fscanf(f, "%d", &n);
    niz = malloc(n * sizeof(STUDENT));
    if (niz == NULL)
        greska();

    char ime[MAX], prezime[MAX];
    int i = 0, ocena, j, suma;
    double prosek;

    while (i < n)
    {
        fscanf(f, "%s%s", ime, prezime);
        strcpy(niz[i].puno_ime, ime);
        strcat(niz[i].puno_ime, " ");
        strcat(niz[i].puno_ime, prezime);

        niz[i].ocene = malloc(10 * sizeof(int));
        if (niz[i].ocene == NULL)
            greska();

        j = 0;
        suma = 0;
        prosek = 0.0;
        /* ucitavamo ocenu po ocenu za i-tog studenta */
        while (1)
        {
            fscanf(f, "%d", &ocena);
            if (ocena == 0)
                break;

            niz[i].ocene[j] = ocena;
            suma += ocena;

            j++;
        }

        /* ako slucajno imamo brojeve i posle 0,
         * hocemo da ucitamo sve do kraja (ali ne da ih upisemo u niz) */
        while (fscanf(f, "%d", &ocena) == 1)
            ;

        if (j == 0)
            prosek = 0.0;
        else
            prosek = (double)suma / j;

        niz[i].broj_ocena = j;
        niz[i].prosek = prosek;

        i++;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s ", niz[i].puno_ime);
    //     for (int j = 0; j < niz[i].broj_ocena; j++)
    //         printf("%d ", niz[i].ocene[j]);
    //     putchar('\n');
    // }

    int index = najveci_prosek(niz, n);
    ispisi(&niz[index]);

    fclose(f);
    free(niz);

    return 0;
}