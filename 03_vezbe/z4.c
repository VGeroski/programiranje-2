/* Zadatak 4:
 * Napisati program koji u datoteci cije se ime zadaje kao argument komandne linije,
 * pronalazi i na standardni izlaz ispisuje sve linije u kojima se zadata rec
 * pojavljuje n puta. Trazena rec i broj pojavljivanja n se zadaju sa standardnog
 * ulaza. Maksimalna duzina reci je 20 karaktera. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska()
{
    fprintf(stderr, "-1");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        greska();

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        greska();

    int n;
    scanf("%d", &n);

    char trazena[MAX];
    scanf("%s", trazena);

    char *linija = NULL;
    unsigned long duzina_linije = 0;
    while (getline(&linija, &duzina_linije, f) != -1)
    {
        // cistimo celu liniju od '\n' da ne bismo posle u tokenu proveravali
        linija[strcspn(linija, "\r\n")] = '\0';
        char *kopija = strdup(linija);

        char *token;
        // belina kao delimiter
        const char *delimiter = " ";

        // Dohvatamo prvi token
        int brojac = 0;
        token = strtok(linija, delimiter);

        // Iteriramo kroz ostale tokene
        while (token != NULL)
        {
            // posto smo ocistili celu liniju, ovo vise nije potrebno
            // if (token[strlen(token) - 1] == '\n')
            //     token[strlen(token) - 1] = '\0';

            if (strcmp(token, trazena) == 0)
                brojac++;

            token = strtok(NULL, delimiter);
        }

        /* Ako je brojac jednak trazenom broju pojavljivanja,
         * ispisujemo tekucu liniju na standardni izlaz */
        if (brojac == n)
            printf("%s\n", kopija);

        free(kopija);
    }

    free(linija);
    fclose(f);

    return 0;
}
