/* 11059 - Maximum Product */

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    short n, n_case = 1;

    while (cin >> n)
    {
        short seq[n];
        long long max_prod = LONG_LONG_MIN;

        for (int i = 0; i < n; i++)
            cin >> seq[i];

        for (int i = 0; i < n; i++)
        {
            long long prod = 1;

            for (int j = i; j < n; j++)
            {
                prod *= seq[j];

                if(prod > max_prod)
                    max_prod = prod;
            }
        }

        if(max_prod < 0)
            max_prod = 0;

        cout << "Case #" << n_case << ": The maximum product is " << max_prod << "." << endl
             << endl;

        n_case++;
    }

    return 0;
}
