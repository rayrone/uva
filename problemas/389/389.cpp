/* 389 - Basically Speaking */

#include <iostream>
#include <iomanip>

using namespace std;

int calculateDecimalValue(char digit)
{
    if(digit >= '0' && digit <= '9')
        return digit - '0';
    else
        return digit - 'A' + 10;
}

long convertTo10Base(string num, int base)
{
    int currentDigit;
    long num10 = 0, pow = 1;

    for(string::reverse_iterator rit = num.rbegin() ; rit != num.rend() ; rit++)
    {
        currentDigit = calculateDecimalValue(*rit);
        num10 = num10 + currentDigit * pow;
        pow *= base;
    }

    return num10;
}

char toCharFromDecimalValue(int value)
{
    if(value >= 0 && value <= 9)
        return static_cast<char>(value + '0');
    else
        return static_cast<char>(value + 'A' - 10);
}

string convertFrom10Base(long num , int base)
{
    int currentDigit;
    string numBase;

    do
    {
        currentDigit = num % base;
        numBase = toCharFromDecimalValue(currentDigit) + numBase;
        num /= base;
    }while(num > 0);

    return numBase;
}

int main()
{
    string num, newNum;
    int baseNum, newBase;

    while(cin >> num >> baseNum >> newBase)
    {
        newNum = convertFrom10Base(convertTo10Base(num, baseNum), newBase);

        if(newNum.length() <= 7)
            cout << setw(7) << newNum << endl;
        else
            cout << setw(7) << "ERROR" << endl;
    }

    return 0;
}
