#include <stdio.h>
#include <stdlib.h>

void f(int *a)
{
    printf("f: %ld\n", sizeof(a));
}

int main(int argc, char *argv[])
{
    int a[10];
    printf("main: %ld\n", sizeof(a));
    f(a);

    for (int i = 0; i < argc; i++)
        printf("%d. %s\n", i + 1, argv[i]);

    return 0;
}