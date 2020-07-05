/* 10878 - Decode the tape */

#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(int n)
{
    int num = n, dec_value = 0, base = 1, temp = num;

    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}

int main()
{
    string line;

    getline(cin, line);

    while (true)
    {
        getline(cin, line);

        if (line == "___________")
            break;

        if (line.empty())
            continue;

        string ascii;

        for (int i = 1; i <= 10; i++)
        {
            if (line[i] == ' ')
                ascii.push_back('0');
            else if (line[i] == 'o')
                ascii.push_back('1');
        }

        cout << (char) binaryToDecimal(stoi(ascii));
    }

    return 0;
}
