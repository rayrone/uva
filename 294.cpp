#include <iostream>

/* 294 - Divisors */

using namespace std;

int numDivisors(int n)
{
    int count, divisorsCount = 1;

    for(int i = 2 ; i * i <= n ; i++)
    {
        count = 0;

        while(!(n % i))
        {
            n /= i;
            count++;
        }

        if(count)
        {
            divisorsCount *= (count + 1);
        }
    }

    if(n > 1)
    {
        divisorsCount *= 2;
    }

    return divisorsCount;
}

void printMaxDivisors(int l, int u)
{
    int divisorsCount, maxDivisors = 0, n;

    for(int i = l ; i <= u ; i++)
    {
        divisorsCount = numDivisors(i);

        if(divisorsCount > maxDivisors)
        {
            maxDivisors = divisorsCount;
            n = i;
        }
    }

    cout << "Between " << l << " and " <<  u << ", " << n << " has a maximum of " << maxDivisors << " divisors." << endl;
}

int main()
{
    int n, l, u;

    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> l >> u;
        printMaxDivisors(l, u);
    }
}
