/* Rotina para ordenar c-strings */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (strcmp((char *)a, (char *)b));
}

int main()
{
    int i, n = 4;
    char names[4][11] = {"Pato", "Gato", "Rato", "Elefante"};

    qsort((void *)names, n, sizeof(names[0]), cmp);

    for (i = 0; i < n; i++)
        puts(names[i]);

    return 0;
}
