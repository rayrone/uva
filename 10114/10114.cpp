#include <iostream>

/* 10114 - Loansome Car Buyer */

using namespace std;

int main()
{
    int complete_months, duration_loan, month_nummber, num_depreciation;
    float amount_loan, car_value, down_payment, installment;

    while(true)
    {
        cin >> duration_loan >> down_payment >> amount_loan >> num_depreciation;

        if(duration_loan < 0)
            break;

        car_value = amount_loan + down_payment;
        installment = amount_loan / duration_loan;

        float depreciation_pcte[101];

        for(int i = 1 ; i <= num_depreciation ; i++)
        {
            cin >> month_nummber >> depreciation_pcte[month_nummber];

            for(int j = month_nummber ; j <= duration_loan ; j++)
                depreciation_pcte[j] = depreciation_pcte[month_nummber];
        }

        for(complete_months = 0 ; complete_months <= duration_loan ; complete_months++)
        {
            car_value -= car_value * depreciation_pcte[complete_months];

            if(complete_months > 0)
                amount_loan -= installment;

            if(car_value > amount_loan)
                break;
        }

        cout << complete_months << " month";

        if(complete_months != 1)
            cout << "s";

        cout << endl;
    }

    return 0;
}
