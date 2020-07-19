/* Factorial */

#include <iostream>

using namespace std;

unsigned long factorial_recursive(unsigned long n)
{
    if (n == 1)
        return 1;

    return n * factorial_recursive(n - 1);
}

unsigned long factorial_iterative(unsigned long n)
{
    unsigned long factorial = 1;

    for (int i = 2; i <= n; i++)
        factorial *= i;

    return factorial;
}

int main()
{
    for (int i = 1; i <= 15; i++)
    {
        cout << "Factorial Recursive of " << i << " is " << factorial_recursive(i) << endl;
        cout << "Factorial Iterative of " << i << " is " << factorial_recursive(i) << endl;
        cout << endl;
    }

    return 0;
}
