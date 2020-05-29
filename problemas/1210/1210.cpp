/* 1210 - Sum of Consecutive Prime Numbers */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000
#define MAXP 1229

int primes[MAXP];

void getPrimes()
{
    int i, j, isprime, psize = 0;

    primes[psize++] = 2;

    for(i = 3; i <= MAXN; i+= 2)
    {
        for(isprime = j = 1; j < psize; j++)
        {
            if(i % primes[j] == 0)
            {
                isprime = 0;
                break;
            }
      
            if(1.0 * primes[j] * primes[j] > i)
              break;
        }

        if(isprime)
          primes[psize++] = i;
    }
}

int main()
{
    int count, n, position, sum;

    getPrimes();

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
          break;

        position = 0;

        while(position < MAXP && n >= primes[position])
            position++;

        count = 0;

        for(int i = 0; i < position ; i++)
        {
            sum = 0;

            for(int j = i ; j < position && sum < n ; j++)
                sum += primes[j];

            if(sum == n)
                count++;
        }

        printf("%d\n", count);
    }
  
    return 0;
}
