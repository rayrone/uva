#include <iostream>

using namespace std;

/* Last nonzero-digit */

int lastNonZeroDigit(int n)
{
    int lastDigit;

    do
    {
        lastDigit = n % 10;
        n /= 10;
    } while(lastDigit == 0);

    return lastDigit;
}

int main()
{
	cout << "lastDigit non-zero: " << lastNonZeroDigit(2) << endl;
	cout << "lastDigit non-zero: " << lastNonZeroDigit(5) << endl;
	cout << "lastDigit non-zero: " << lastNonZeroDigit(8) << endl;
	cout << "lastDigit non-zero: " << lastNonZeroDigit(12) << endl;
	cout << "lastDigit non-zero: " << lastNonZeroDigit(230) << endl;
	cout << "lastDigit non-zero: " << lastNonZeroDigit(1234) << endl;

	return 0;
}
