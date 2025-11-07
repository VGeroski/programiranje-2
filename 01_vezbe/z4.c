#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int jednak_zbiru_suseda(int matrica[MAX][MAX], int m, int n, int i, int j)
{
    int zbir = 0;

    // da li postoje elementi iznad
    if (i - 1 >= 0)
    {
        zbir += matrica[i - 1][j];

        if (j - 1 >= 0)
            zbir += matrica[i - 1][j - 1];

        if (j + 1 < n)
            zbir += matrica[i - 1][j + 1];
    }

    // da li smo u poslednjoj vrsti
    if (i + 1 < m)
    {
        zbir += matrica[i + 1][j];

        if (j - 1 >= 0)
            zbir += matrica[i + 1][j - 1];

        if (j + 1 < n)
            zbir += matrica[i + 1][j + 1];
    }

    // kolona levo da li postoji
    if (j - 1 >= 0)
    {
        zbir += matrica[i][j - 1];

        // Vec smo izracunali ovaj deo
        // if (i - 1 >= 0)
        //     zbir += matrica[i - 1][j - 1];
        
        // if (i + 1 >= 0)
        //     zbir += matrica[i + 1][j - 1];
    }

    // kolona desno da li postoji
    if (j + 1 >= 0)
    {
        zbir += matrica[i][j + 1];

        // Vec smo izracunali ovaj deo
        // if (i - 1 >= 0)
        //     zbir += matrica[i - 1][j + 1];
        
        // if (i + 1 >= 0)
        //     zbir += matrica[i + 1][j + 1];
    }

    // if (zbir == matrica[i][j])
    //     return 1;
    // else
    //     return 0;

    return zbir == matrica[i][j];
}

int main()
{
    FILE *ulaz = fopen("matrica.txt", "r");
    if (ulaz == NULL)
        greska();

    int matrica[MAX][MAX];
    int m, n;

    fscanf(ulaz, "%d%d", &m, &n);

    // ucitavanje matrice
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fscanf(ulaz, "%d", &matrica[i][j]);

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         printf("%d ", matrica[i][j]);

    //     printf("\n");
    // }

    // za svaki element matrice proveravamo da li je zbir svih svojih suseda
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (jednak_zbiru_suseda(matrica, m, n, i, j))
            {
                printf("(%d %d %d)\n", i, j, matrica[i][j]);
            }
        }

    fclose(ulaz);
    return 0;
}