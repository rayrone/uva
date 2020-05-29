/* 264 - Count on Cantor */

#include <iostream>

using namespace std;

int main()
{
    int n, maxN = 5001;
    long v[maxN];

    for (int i = 1; i < maxN; i++)
        v[i] = 1 + i * (i - 1) / 2;

    while (cin >> n)
    {
        int index = 1;
        
        while(v[index + 1] <= n)
            index++;

        int num, den;

        if (index % 2 == 0)
        {
            num = n - v[index] + 1;
            den = index - num + 1;
        }
        else
        {
            den = n - v[index] + 1;
            num = index - den + 1;
        }

        cout << "TERM " << n << " IS " << num  << "/" << den << endl;
    }

    return 0;
}
