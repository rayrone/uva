/*  100 - The 3n + 1 problem */

#include <iostream>

using namespace std;

int cycleLength(int n)
{
    int length = 1;

    while(n > 1)
    {
        if(n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;

        length++;
    }

    return length;
}

int maxCycleLength(int i, int j)
{
    int currentCycle, maxCycle = 1;

    if(i > j)
    {
        // Swap values
        i ^= j;
        j ^= i;
        i ^= j;
    }

    if(i < j / 2)
        i = j / 2;

    for(int k = i ; k <= j ; k++)
    {
        currentCycle = cycleLength(k);

        if(currentCycle > maxCycle)
            maxCycle = currentCycle;
    }

    return maxCycle;
}

int main()
{
    int i, j;

    while(cin >> i >> j)
        cout << i << " " << j << " " << maxCycleLength(i, j) << endl;
}