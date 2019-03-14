#include <iostream>

/* 11172 - Relational Operator */

using namespace std;

int main()
{
    int i, t;
    long a, b;

    cin >> t;

    for (i = 1; i <= t; i++)
    {
        cin >> a >> b;

        if(a > b)
            cout << ">";
        else if(a < b)
            cout << "<";
        else
            cout << "=";

        cout << endl;
    }

    return 0;
}
