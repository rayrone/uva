/* 10680 - LCM */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000001;

vector<int> prime_factors;

void preprocess()
{
    vector<bool> prime(MAXN, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i])
        {
            prime_factors.push_back(i);
            for (int j = i + i; j < MAXN; j += i)
                prime[j] = false;
        }
    }

    swap(prime_factors[1], prime_factors[2]); // SWAP 3,5
}

int main()
{
    int n, res, c2, c5;

    preprocess();

    while (cin >> n)
    {
        if (n == 0)
            break;

        res = 1;
        c2 = c5 = 0;

        for (int i = 2; i <= n; i *= 2)
            c2++;

        for (int i = 5; i <= n; i *= 5)
            c5++;

        for (int i = 0; i < c2 - c5; ++i)
            res = (res * 2) % 10;

        for (int i = 2; i < prime_factors.size(); ++i)
        {
            if (prime_factors[i] > n)
                break;

            for (long j = prime_factors[i]; j <= n; j *= prime_factors[i])
                res = (res * prime_factors[i]) % 10;
        }

        cout << res << endl;
    }

    return 0;
}
