#include <iostream>

/* 11498 - Division of Nlogonia */

using namespace std;

int main()
{
    int i, k, m, n, x, y;

    while(cin >> k)
    {
        if(k == 0)
            break;

        cin >> n >> m;

        for(i = 1 ; i <= k ; i++)
        {
            cin >> x >> y;

            if(x == n || y == m)
                cout << "divisa";
            else if(x < n && y > m)
                cout <<"NO";
            else if(x > n && y > m)
                cout << "NE";
            else if(x > n && y < m)
                cout <<"SE";
            else
                cout << "SO";

            cout << endl;
        }
    }

    return 0;
}
