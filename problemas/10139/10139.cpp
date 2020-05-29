/* 10139 - Factovisors */

#include <iostream>
#include <vector>

#define MAXP 1000000

using namespace std;

long long primes[MAXP];

long long pfif(long long k, long long n)
{
    long long pow, sum = 0;

    for (pow = k; pow <= n; pow *= k)
        sum += n / pow;
    
    return sum;
}

void getPrimes()
{
    long long i, j, isprime, psize = 1;

    primes[0] = 2;

    for (i = 3; i <= MAXP; i += 2)
    {
        for (isprime = j = 1; j < psize; j++)
        {
            if (i % primes[j] == 0)
            {
                isprime = 0;
                break;
            }
    
            if (1.0 * primes[j] * primes[j] > i)
                break;
        }
    
        if (isprime)
            primes[psize++] = i;
    }
}

long long fif(long long k, long long n)
{
    long long i, p, m, tmp, min = 2000000000;

    for (i = 0; k > 1; i++)
    {
        p = primes[i];
        
        if (p * p > k)
            p = k;
        
        for (m = 0; k % p == 0; m++)
            k /= p;
        
        if (!m)
            continue;
        
        tmp = pfif(p, n) / m;
        
        if (tmp < min)
            min = tmp;
    }
    
    return min;
}

int main()
{
    long long n, m;

    getPrimes();

    while (cin >> n >> m)
    {
        if (fif(m, n) > 0)
            cout << m << " divides " << n << "!" << endl;
        else
            cout << m << " does not divide " << n << "!" << endl;
    }

    return 0;
}
