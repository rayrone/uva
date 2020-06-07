/* 10189 - Minesweeper */

#include <stdio.h>

int main()
{
    int n, m, cont = 0, campo = 0;
    char vet[102], mat[102][103];

    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                mat[i][j] = '.';

        for (int i = 1; i <= n; i++)
        {
            scanf("%s", vet);

            for (int j = 1; j <= m; j++)
                mat[i][j] = vet[j - 1];
        }

        campo++;

        if (campo != 1)
            printf("\n");

        printf("Field #%d:", campo);

        for (int i = 1; i <= n; i++)
        {
            printf("\n");

            for (int j = 1; j <= m; j++)
            {
                if (mat[i][j] != '.')
                {
                    printf("*");
                    continue;
                }

                cont = 0;

                if (mat[i - 1][j - 1] == '*')
                    cont++;
                if (mat[i - 1][j] == '*')
                    cont++;
                if (mat[i - 1][j + 1] == '*')
                    cont++;
                if (mat[i][j - 1] == '*')
                    cont++;
                if (mat[i][j + 1] == '*')
                    cont++;
                if (mat[i + 1][j - 1] == '*')
                    cont++;
                if (mat[i + 1][j] == '*')
                    cont++;
                if (mat[i + 1][j + 1] == '*')
                    cont++;

                printf("%d", cont);
            }
        }

        printf("\n");
    }

    return 0;
}
