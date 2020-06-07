#include<stdio.h>
#include<string.h>

/* 119 - Greedy Gift Givers */

typedef struct
{
    int money;
    char name[13];
}givers;

int main()
{
    int i, j, k, n, m, loss;
    char flag = 0, aux[13];
    givers people[10];

    while(scanf("%d", &n)!=EOF)
    {
        if(flag)
        {
            printf("\n");
        }
        else
        {
            flag = 1;
        }

        for(i = 0 ; i < n ; i++)
        {
            people[i].money = 0;
        }

        for(i = 0 ; i < n ; i++)
        {
            scanf("%s", people[i].name);
        }

        for(k = 1 ; k <= n ; k++)
        {
            scanf("%s %d %d", aux, &loss, &m);

            for(i = 0 ; i < n ; i++)
            {
                if(!strcmp(people[i].name, aux))
                {
                    if(m != 0)
                    {
                        people[i].money -= loss - loss % m;
                    }
                }
            }

            for(i = 0 ; i < m ;i++)
            {
                scanf("%s", aux);

                for(j = 0 ; j < n; j++)
                {
                    if(!strcmp(people[j].name, aux))
                    {
                        people[j].money += loss / m;
                    }
                }
            }
        }

        for(i = 0 ; i < n ; i++)
        {
            printf("%s %d\n", people[i].name, people[i].money);
        }
    }
}
