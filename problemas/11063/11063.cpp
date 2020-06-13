/* 11063 - B2-Sequence */

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n, n_case = 1;

    while (cin >> n)
    {
        int seq[n];

        for (int i = 0; i < n; i++)
            cin >> seq[i];

        bool b2_sequence = true;
        unordered_set<int> pairs_set;
        pair<unordered_set<int>::iterator, bool> ret;

        for (int i = 0; i < n; i++)
        {
            if (seq[i] < 1)
            {
                b2_sequence = false;
                break;
            }

            for (int j = i; j < n; j++)
            {
                if (seq[i] > seq[j])
                {
                    b2_sequence = false;
                    break;
                }

                ret = pairs_set.insert(seq[i] + seq[j]);

                if (!ret.second)
                {
                    b2_sequence = false;
                    break;
                }
            }

            if (!b2_sequence)
                break;
        }

        cout << "Case #" << n_case++ << ": ";

        if (b2_sequence)
            cout << "It is a B2-Sequence." << endl;
        else
            cout << "It is not a B2-Sequence." << endl;

        cout << endl;
    }

    return 0;
}
