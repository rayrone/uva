/* 880 - Cantor Fractions */

#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    long long n, diagonal;

    while (cin >> n)
    {
        // BSearch for find first element at diagonal

        unsigned long long first_fraction_diagonal, last_fraction_diagonal;
        unsigned long long inf = 1, mid = 1, sup = LONG_LONG_MAX;

        while (inf <= sup)
        {
            mid = (inf + sup) / 2;
            first_fraction_diagonal = 1 + mid * (mid - 1) / 2;
            last_fraction_diagonal = first_fraction_diagonal + mid - 1;

            if (n >= first_fraction_diagonal && n <= last_fraction_diagonal)
                break;

            if (n < first_fraction_diagonal)
                sup = mid - 1;

            if (n > last_fraction_diagonal)
                inf = mid + 1;
        }

        unsigned long long diff = n - first_fraction_diagonal;

        cout << mid - diff << "/" << 1 + diff << endl;
    }

    return 0;
}
