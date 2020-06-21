/* 673 - Parentheses Balance */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string str)
{
    int s_size = str.size();
    stack<char> stack;

    for (int i = 0; i < s_size; i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            stack.push(str[i]);
            continue;
        }

        if (stack.empty())
            return false;

        if ((str[i] == ')' && stack.top() == '(') || (str[i] == ']' && stack.top() == '['))
            stack.pop();
        else
            return false;
    }

    return stack.empty();
}

int main()
{
    int n;
    string str;

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        getline(cin, str);

        if (isBalanced(str))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
