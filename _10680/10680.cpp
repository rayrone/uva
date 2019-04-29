/* 10680 - LCM */

#include <iostream>
#include <vector>

#define MAXN 1000000
#define MAXP 78498

using namespace std;

int primes[MAXP];
int psize;

void getPrimes()
{
    int i, j, isprime;

    psize = 0;
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

typedef struct
{
    int size;
  	int f[32];
} Factors;

Factors getPFactor(int n)
{
    Factors x;

  	x.size = 0;
  
  	for(int i = 0; i < psize; i++)
  	{
    	while(n % primes[i] == 0)
    	{
      		x.f[x.size++] = primes[i];
      		n /= primes[i];
    	}
    
    	if(1.0 * primes[i] * primes[i] > n)
    		break;
  	}
  
  	if(n > 1)
  	{
  		x.f[x.size++] = n;
  	}
  
  	return x;
}

int main()
{
    Factors x;
    int n, max = 0;

    getPrimes();

    cout << "psize: " << psize << endl;

    for(int i = 2 ; i <= MAXN ; i++)
    {
    	x =  getPFactor(i);

    	if(x.size > max)
    		max = x.size;

    	/*printf("%d = ", i);

    	for(int j = 0; j < x.size; j++)
        {
            if(j)
              printf(" x ");
      
            printf("%d", x.f[j]);
        }
    
        printf("\n");*/
    }

    cout << "max: " << max;

    return 0;
}
