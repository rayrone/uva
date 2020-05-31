/* 12995 - Farey Sequence */

#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 1000001

int phi(int n)
{
    int i, count, res = 1;

    for (i = 2; i * i <= n; i++)
    {
        count = 0;
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
        if (count > 0)
            res *= (pow(i, count) - pow(i, count - 1));
    }

    if (n > 1)
        res *= (n - 1);

    return res;
}

int main()
{
    int n, phiN;
    static unsigned long long v[MAX_N];

    for (int i = 2; i < MAX_N; i++)
    {
        phiN = phi(i);
        v[i] = v[i - 1] + phiN;
    }

    while (cin >> n)
    {
        if (n == 0)
            break;

        cout << v[n] << endl;
    }

    return 0;
}