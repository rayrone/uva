#include <iostream>
#include <limits>

/* 11559 - Event Planning */

using namespace std;

int main()
{
    int budget, num_hotels, num_participants, num_weeks;

    while(cin >> num_participants >> budget >> num_hotels >> num_weeks)
    {
        int min_cost = INT32_MAX;
        bool stayHome = true;

        for(int i = 1 ; i <= num_hotels ; i++)
        {
            int cost, price;
            int beds[13];

            cin >> price;

            for(int j = 0 ; j < num_weeks ; j++)
                cin >> beds[j];

            cost = price * num_participants;

            if(cost > budget)
                continue;

            for(int j = 0 ; j < num_weeks ; j++)
            {
                if(beds[j] >= num_participants)
                {
                    min_cost = min(min_cost, cost);
                    stayHome = false;
                    break;
                }
            }
        }

        if(stayHome)
            cout << "stay home" << endl;
        else
            cout << min_cost << endl;
    }

    return 0;
}
