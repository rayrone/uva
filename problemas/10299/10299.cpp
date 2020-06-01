/* 10299 - Relatives */

#include <iostream>
#include <math.h>

using namespace std;

int phi(int n)
{
    int i, count, res = 1;

    if (n == 1)
        return 0;

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
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        cout << phi(n) << endl;
    }

    return 0;
}
