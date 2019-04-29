#include <iostream>
#include <iomanip>
#include <math.h>

/* 10200 - Prime Time */

#define ONEPRIME false

using namespace std;

bool isPrime(int x)
{
    int i;

    if(x == 1)
    {
        return ONEPRIME;
    }

    if(x == 2)
    {
        return true;
    }

    if(x % 2 == 0)
    {
        return false;
    }

    for(i = 3 ; i * i <= x ; i += 2)
    {
        if(x % i == 0)
        {
            return false;
        }
    }

    return true;
}

int eulerPrime(int n)
{
    return n * n + n + 41;
}

void printPrimePercentage(float primePercentage)
{
    cout << fixed << setprecision(2) << round(primePercentage * 100) / 100 << endl;
}

int main()
{
    int a, b, primeCount, totalNumbers;
    bool primes[10001];

    // Calculando todos os números gerados pela fórmula de euler em um intervalo de 0 a 10000
    for(int i = 0 ; i <= 10000 ; i++)
    {
        primes[i] = isPrime(eulerPrime(i));
    }

    while(cin >> a >> b)
    {
        primeCount = 0;
        totalNumbers = b - a + 1;

        for(int i = a ; i <= b ; i++)
        {
            if(primes[i])
            {
                primeCount++;
            }
        }

        printPrimePercentage((float) primeCount / (float) totalNumbers * 100);
    }

    return 0;
}
