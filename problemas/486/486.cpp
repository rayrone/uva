/* 486 - English-Number Translator */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define NEGATIVE "negative"
#define HUNDRED "hundred"
#define THOUSAND "thousand"
#define MILLION "million"

vector<string> split(string str)
{
    char separator = ' ';
    vector<string> tokens;
    string token;
    size_t begin = 0, end, len;

    while (true)
    {
        end = str.find(separator, begin);

        if (end == string::npos)
            break;

        len = end - begin;
        token = str.substr(begin, len);
        tokens.push_back(token);
        begin = end + 1;
    }

    // last token
    token = str.substr(begin);
    tokens.push_back(token);

    return tokens;
}

int main()
{
    map<string, long> dictionary;

    dictionary["zero"] = 0;
    dictionary["one"] = 1;
    dictionary["two"] = 2;
    dictionary["three"] = 3;
    dictionary["four"] = 4;
    dictionary["five"] = 5;
    dictionary["six"] = 6;
    dictionary["seven"] = 7;
    dictionary["eight"] = 8;
    dictionary["nine"] = 9;
    dictionary["ten"] = 10;
    dictionary["eleven"] = 11;
    dictionary["twelve"] = 12;
    dictionary["thirteen"] = 13;
    dictionary["fourteen"] = 14;
    dictionary["fifteen"] = 15;
    dictionary["sixteen"] = 16;
    dictionary["seventeen"] = 17;
    dictionary["eighteen"] = 18;
    dictionary["nineteen"] = 19;
    dictionary["twenty"] = 20;
    dictionary["thirty"] = 30;
    dictionary["forty"] = 40;
    dictionary["fifty"] = 50;
    dictionary["sixty"] = 60;
    dictionary["seventy"] = 70;
    dictionary["eighty"] = 80;
    dictionary["ninety"] = 90;
    dictionary[HUNDRED] = 100;
    dictionary[THOUSAND] = 1000;
    dictionary[MILLION] = 1000000;

    string description;

    while (getline(cin, description))
    {
        vector<string> tokens = split(description);

        long number = 0;
        bool isNegativeNumber;
        int index;

        if (tokens[0] == NEGATIVE)
        {
            index = 1;
            isNegativeNumber = true;
        }
        else
        {
            index = 0;
            isNegativeNumber = false;
        }

        string token;

        long partial = 0;

        for (; index < tokens.size(); index++)
        {
            token = tokens[index];

            if (token == HUNDRED)
            {
                partial = partial * dictionary[token];
                continue;
            }

            if (token == THOUSAND || token == MILLION)
            {
                partial = partial * dictionary[token];
                number += partial;
                partial = 0;
                continue;
            }

            partial += dictionary[token];
        }

        number += partial;

        number = isNegativeNumber ? -number : number;
        cout << number << endl;
    }

    return 0;
}