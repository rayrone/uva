/* 10104 - Euclid Problem */

#include <iostream>
#include <math.h>

using namespace std;

/* Find the gcd(p,q) and x,y such that p*x + q*y = gcd(p,q) */
long gcd(long p, long q, long *x, long *y)
{
    /* previous coefficients */
    long x1, y1;

    /* value of gcd(p,q) */
    long g;

    if (q > p)
        return (gcd(q, p, y, x));

    if (q == 0)
    {
        *x = 1;
        *y = 0;
        return (p);
    }

    g = gcd(q, p % q, &x1, &y1);
    *x = y1;
    *y = (x1 - floor(p / q) * y1);

    return (g);
}

int main()
{
    long a, b, g, x, y;

    while (cin >> a >> b)
    {
        g = gcd(a, b, &x, &y);
        cout << x << " " << y << " " << g << endl;
    }

    return 0;
}
