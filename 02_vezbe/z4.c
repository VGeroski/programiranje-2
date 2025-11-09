/* Zadatak 4:
 * Napisati program koji sa standardnog ulaza ucitava matricu celih brojeva. Prvo se ucitaju broj
 * vrsta i kolona matrice, a zatim i elementi matrice. Na standardni izlaz ispisati ucitanu matricu.
 * Zatim napisati funkciju - int sum max(int **A, int n, int m)
 * koja racuna zbir najvecih elemenata u svakoj vrsti.
 * Ispisati rezultat izvrsavanja funkcije na std izlaz. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int sum_max(int **A, int n, int m)
{
    int zbir = 0, max;
    for (int i = 0; i < m; i++)
    {
        max = A[i][0];
        for (int j = 0; j < n; j++)
            if (A[i][j] > max)
                max = A[i][j];

        zbir += max;
    }

    return zbir;
}

int main()
{
    int **matrica;
    int n, m;

    scanf("%d%d", &m, &n);

    matrica = malloc(m * sizeof(int *));
    if (matrica == NULL)
        greska();

    for (int i = 0; i < m; i++)
    {
        matrica[i] = malloc(n * sizeof(int));
        if (matrica[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matrica[j]);
            free(matrica);

            greska();
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrica[i][j]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matrica[i][j]);
        putchar('\n');
    }

    printf("Zbir: %d\n", sum_max(matrica, n, m));

    for (int i = 0; i < m; i++)
        free(matrica[i]);
    free(matrica);

    return 0;
}