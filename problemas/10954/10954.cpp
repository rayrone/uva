/* 10954 - Add All */

#include <iostream>
#include <queue>

using namespace std;

int compare(const void *a, const void *b)
{
    return (int *)a - (int *)b;
}

int main()
{
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        priority_queue<long long, vector<long long>, greater<long long>> q;

        int num;

        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            q.push(num);
        }

        long long num1, num2, sum, min_cost = 0;

        while (q.size() > 1)
        {
            num1 = q.top();
            q.pop();
            num2 = q.top();
            q.pop();
            
            sum = num1 + num2;
            min_cost += sum;
            q.push(sum);
        }

        cout << min_cost << endl;
    }

    return 0;
}
