#include <iostream>
#include <vector>

#define MAXN 1001

/* Generating List of Primes - Sieve of Eratosthenes */

using namespace std;

vector<bool> is_prime(MAXN, true);

void getPrimes()
{
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i * i <= MAXN; i++)
    {
        if(is_prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
	int n;

	getPrimes();

	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;

		for(int i = 0; i <= MAXN; i++)
        	if(is_prime[i])
          		cout << i << " | " << is_prime[i] << endl;
	}

	return 0;
}
