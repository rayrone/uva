/* 10323 - Factorial! You Must be Kidding!!! */

#include <iostream>

using namespace std;

int main()
{
    int n;
    unsigned long factorials_from_8_to_13[6] = {40320, 362880, 3628800, 39916800, 479001600, 6227020800};

    while (cin >> n)
    {
        if (n >= 8 && n <= 13)
            cout << factorials_from_8_to_13[n - 8] << endl;
        else if(n > 13 || (n < 0 && ((-n) % 2 == 1)))
            cout << "Overflow!" << endl;
        else
            cout << "Underflow!" << endl;
    }

    return 0;
}