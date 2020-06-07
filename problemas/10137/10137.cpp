/* 10137 - The Trip */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numStudents;

    while (cin >> numStudents)
    {
        if (numStudents == 0)
            break;

        double amountSpent[numStudents];
        double meanAmountSpent = 0.0;

        for (int i = 0; i < numStudents; i++)
        {
            cin >> amountSpent[i];
            meanAmountSpent += amountSpent[i];
        }

        meanAmountSpent = meanAmountSpent / numStudents;

        double amountChangeBelowMean = 0;
        double amountChangeAboveMean = 0;
        double diff;

        for (int i = 0; i < numStudents; i++)
        {
            /* to ensure 0.01 precision */
            diff = (double)(long)((amountSpent[i] - meanAmountSpent) * 100) / 100.0;

            if (diff > 0)
                amountChangeAboveMean += diff;
            else
                amountChangeBelowMean += diff;
        }

        double minAmountChange = max(abs(amountChangeBelowMean), amountChangeAboveMean);

        printf("$%.2f\n", minAmountChange);
    }

    return 0;
}
