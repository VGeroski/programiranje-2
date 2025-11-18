#include "polinom.h"

int main()
{
    int n, m;
    int *p1 = unos(&n);
    int *p2 = unos(&m);

    int *c;
    int suma = suma_polinoma(p1, n, p2, m, &c);

    ispis_polinoma(c, suma);

    mnoz_skalar(p1, n, 10);
    ispis_polinoma(p1, n);

    int x = vr_poly(p1, n, 2);
    printf("\nvrednost polinoma u tacki 2: %d\n", x);

    int *mul;
    int s = mul_poly(p1, n, p2, m, &mul);
    ispis_polinoma(mul, s);

    free(p1);
    free(p2);
    free(c);
    free(mul);

    return 0;
}
