#include <iostream>
#include <cmath>

/* 343 - What Base Is This? */

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
    int currDigit;
    long num10 = 0, pow = 1;

    for(string::reverse_iterator rit = num.rbegin() ; rit != num.rend() ; rit++)
    {
        currDigit = calculateDecimalValue(*rit);
        num10 = num10 + currDigit * pow;
        pow *= base;
    }

    return num10;
}

int findSmallestBase(string num)
{
    int digitValue, smallestBase = 1;

    for(string::reverse_iterator rit = num.rbegin() ; rit != num.rend() ; rit++)
    {
        digitValue = calculateDecimalValue(*rit);
        smallestBase = max(digitValue, smallestBase);
    }

    return smallestBase + 1;
}

int main()
{
    string x, y;
    int bx, by;
    long v_x[37], v_y[37];

    while(cin >> x >> y)
    {
        bx = findSmallestBase(x);
        by = findSmallestBase(y);

        for(int i = bx ; i <= 36 ; i++)
            v_x[i] = convertTo10Base(x, i);

        for(int i = by ; i <= 36 ; i++)
            v_y[i] = convertTo10Base(y, i);

        for(int i = bx ; i <= 36 ; i++)
        {
            for(int j = by ; j <= 36 ; j++)
            {
                if(v_x[i] == v_y[j])
                {
                    cout << x << " (base " << i << ") = " << y <<  " (base " << j << ")" << endl;
                    goto found;
                }
            }
        }

        cout << x << " is not equal to " << y << " in any base 2..36" << endl;

        found:
        x = "";
    }

    return 0;
}
