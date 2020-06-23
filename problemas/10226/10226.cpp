/* 10226 - Hardwood Species */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n_cases;
    string line;

    cin >> n_cases;
    cin.ignore();
    getline(cin, line);

    for (int i = 1; i <= n_cases; i++)
    {
        map<string, int> species;
        int n_trees = 0;

        while (getline(cin, line))
        {
            if (line.empty() && !species.empty())
                break;

            n_trees++;
            species[line]++;
        }

        for (map<string, int>::iterator it = species.begin(); it != species.end(); it++)
            printf("%s %.4f\n", it->first.c_str(), (float)100 * it->second / n_trees);

        if (i != n_cases)
            putchar('\n');
    }

    return 0;
}
