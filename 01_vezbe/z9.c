#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
        // proveravamo da li je ovo opcija
        if (argv[i][0] == '-')
        {
            int n = strlen(argv[i]);

            for (int j = 1; j < n; j++)
                printf("%c ", argv[i][j]);
        }

    return 0;
}