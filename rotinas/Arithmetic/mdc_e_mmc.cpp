/* Calcula o mdc e mmc de dois numeros. */

#include <stdio.h>
#include <math.h>

/* Algoritmo de Euclides Recursivo */
int mdc_recursivo(int a, int b)
{
    return b == 0 ? a : mdc_recursivo(b, a % b);
}

/* Algoritmo de Euclides Iterativo */
int mdc_iterativo(int a, int b)
{
    int r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int mmc(int a, int b)
{
    return (a * b) / mdc_iterativo(a, b);
}

/* 
    Algoritmo de Euclides
    Find the mdc(p,q) and x,y such that p*x + q*y = mdc(p,q) 
*/
long mdc(long p, long q, long *x, long *y)
{
    /* previous coefficients */
    long x1, y1;

    /* value of mdc(p,q) */
    long g;

    if (q > p)
        return (mdc(q, p, y, x));

    if (q == 0)
    {
        *x = 1;
        *y = 0;
        return (p);
    }

    g = mdc(q, p % q, &x1, &y1);
    *x = y1;
    *y = (x1 - floor(p / q) * y1);

    return (g);
}

int main()
{
    int a, b;
 
    printf("MMC\n");
    printf("mmc(30, 60) = %d\n", mmc(30, 60));
    printf("mmc(60, 100) = %d\n", mmc(60, 100));
    printf("mmc(36, 14) = %d\n", mmc(36, 14));

    // Teste da versão recursiva
    printf("\nMDC recursivo\n");
    printf("mdc(30, 60) = %d\n", mdc_recursivo(30, 60));
    printf("mdc(50, 12) = %d\n", mdc_recursivo(50, 12));
    printf("mdc(100, 11) = %d\n", mdc_recursivo(100, 11));
    
    // Teste da versão iterativa
    printf("\nMDC iterativo\n");
    printf("mdc(30, 60) = %d\n", mdc_iterativo(30, 60));
    printf("mdc(50, 12) = %d\n", mdc_iterativo(50, 12));
    printf("mdc(100, 11) = %d\n", mdc_iterativo(100, 11));

    return 0;
}
