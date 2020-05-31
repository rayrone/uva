/* Rotina para inverter um número */

#include <stdio.h>

int reserve(int n)
{
    int aux = n, w = 0, y;

    while (aux != 0)
    {
        w = w * 10 + aux % 10;
        aux /= 10;
    }

    return w;
}

int main()
{
    printf("%d\n", reserve(10));
    printf("%d\n", reserve(4));
    printf("%d\n", reserve(202));
    printf("%d\n", reserve(987));
    printf("%d\n", reserve(580));

    return 0;
}
