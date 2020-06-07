/* 113 - Power of Cryptography */

#include <stdio.h>
#include <math.h>

int main()
{
    double base, expoente;

    while (scanf("%lf %lf", &expoente, &base) != EOF)
        printf("%.0lf\n", floor(0.5 + pow(base, 1.0 / expoente)));

    return 0;
}
