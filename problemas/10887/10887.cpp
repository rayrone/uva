/* 10887 - Concatenation of Languages */

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int t, m, n;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> m >> n;
        cin.ignore();

        string langA[m];
        string langB[n];
        unordered_set<string> langC;

        for (int j = 0; j < m; j++)
            getline(cin, langA[j]);

        for (int k = 0; k < n; k++)
            getline(cin, langB[k]);

        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                langC.insert(langA[j] + langB[k]);

        cout << "Case " << i << ": " << langC.size() << endl;
    }

    return 0;
}
