/* 11727 - Cost Cutting */

#include <iostream>

using namespace std;

bool isBetween(int target, int value1, int value2)
{
    return (target < value1 && target > value2) || (target < value2 && target > value1);
}

int main()
{
    int i, t, s1, s2, s3;

    cin >> t;

    for(i = 1 ; i <= t ; i++)
    {
        cin >> s1 >> s2 >> s3;

        cout << "Case " << i << ": ";

        if(isBetween(s1, s2, s3))
            cout << s1;
        else if(isBetween(s2, s1, s3))
            cout << s2;
        else
            cout << s3;

        cout << endl;
    }

    return 0;
}
