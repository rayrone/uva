/* 10408 - Farey sequences */

#include <iostream>

using namespace std;

void farey(int n, int term)
{
    int h = 0, k = 1, x = 1, y = 0, count_term = 0;

    do
    {
        if (term == count_term)
        {
            cout << h << '/' << k << endl;
            return;
        }

        count_term++;

        int r = (n - y) / k;
        y += r * k;
        x += r * h;

        swap(x, h);
        swap(y, k);
        x = -x;
        y = -y;
    } while (k > 1);

    cout << "1/1" << endl;
}

int main()
{
    int n, k;

    while (cin >> n >> k)
        farey(n, k);

    return 0;
}