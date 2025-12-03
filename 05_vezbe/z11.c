/**
 * Napisati rekurzivnu funkciju int skalarni(int *a, int *b, int n)
 * koja racuna skalarni proizvod a i b
 */

#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

/* [1 2 4] [7 8 6] -> 1*7 + 2*4 + 4*6 */
int skalarni(int *a, int *b, int n)
{
    if (n == 0)
        return 0;

    int rez = skalarni(a, b, n - 1); /* 1*7 + 2*8 */
    return rez + a[n - 1] * b[n - 1];
}

int main()
{
    int *a = NULL;
    int *b = NULL;
    int n;

    printf("Unesi broj elemenata niza: ");
    scanf("%d", &n);
    if (n <= 0)
        greska();

    a = malloc(n * sizeof(int));
    b = malloc(n * sizeof(int));
    if (a == NULL || b == NULL)
        greska();

    printf("Unesi elemente prvog niza: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Unesi elemente drugog niza: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Skalarni proizvod je: %d\n", skalarni(a, b, n));

    return 0;
}