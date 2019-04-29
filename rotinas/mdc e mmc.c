#include <stdio.h>

/* Calcula o mdc e mmc de dois números. */

int mdc(int a, int b)
{
    if(b != 0)
		  return mdc(b, a%b);
    else
 	    return a;
}

int mmc(int a, int b)
{
    return (a * b) /  mdc(a, b);
}

int main()
{
    int a, b;
 
    while(1)
    {
        scanf("%d %d", &a, &b);

        if(a == 0 && b == 0)
          break;

        printf("A = %d e B = %d\n", a, b);
        printf("MDC %d\n", mdc(a, b));
        printf("MMC %d\n", mmc(a, b));
    }

    return 0;
}
