/* StringUtil */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
