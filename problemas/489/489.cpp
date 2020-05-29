/* 489 - Hangman Judge */

#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string str)
{
    string unique;
    
    for (int i = 0 ; i < str.size() ; i++)
        if(unique.find(str[i]) == string::npos)
            unique += str[i];

    return unique;
}

int main()
{
    int round;
    string guesses, solution;

    while (true)
    {
        cin >> round;

        if (round == -1)
            break;

        cin >> solution >> guesses;

        int count = 0, strikes = 0;

        solution = removeDuplicates(solution);
        guesses = removeDuplicates(guesses);

        for (int i = 0; i < guesses.size(); i++)
        {
            if (strikes == 7)
                break;
            
            bool found = false;

            if(solution.find(guesses[i]) != string::npos)
                count++;
            else
                strikes++;

            if(count == solution.size())
                break;
        }

        cout << "Round " << round << endl;

        if (count == solution.size())
            cout << "You win." << endl;
        else if (strikes == 7)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
    }

    return 0;
}
