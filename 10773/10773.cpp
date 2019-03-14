#include <iostream>
#include <cmath>

/* 10773 - Back to Intermediate Math */

using namespace std;

int main()
{
    int num_test_case;
    double d, v, u, time_shortest_path, time_fastest_path;

    cin >> num_test_case;

    for(int i = 1 ; i <= num_test_case ; i++)
    {
        cin >> d >> v >> u;

        if(v >= u || u <= 0.0 || v <= 0.0)
        {
            printf("Case %d: can't determine\n", i);
            continue;
        }

        time_shortest_path = d / u;
        time_fastest_path = d / sqrt(u*u-v*v);

        printf("Case %d: %.3lf\n", i, fabs(time_shortest_path-time_fastest_path));
    }

    return 0;
}
