/* 10925 - Krakovia */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string sum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
}

string divide(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';

    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    return ans.length() == 0 ? "0" : ans;
}

int main()
{
    int n_itens, n_friends, n_bill = 0;

    while (cin >> n_itens >> n_friends)
    {
        if (n_itens == 0 && n_friends == 0)
            break;

        n_bill++;

        string v_item, total_itens = "0";

        for (int i = 1; i <= n_itens; i++)
        {
            cin >> v_item;
            total_itens = sum(total_itens, v_item);
        }

        string v_payment = divide(total_itens, n_friends);

        printf("Bill #%d costs %s: each friend should pay %s\n\n", n_bill, total_itens.c_str(), v_payment.c_str());
    }

    return 0;
}
