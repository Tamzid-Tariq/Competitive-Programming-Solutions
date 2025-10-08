/*
Problem: Missing Number
Link: https://cses.fi/problemset/task/1083/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    ll a;

    cin >> a;

    ll num[a + 1];

    for (ll i = 0; i < a - 1; i++)
    {

        cin >> num[i];
    }
    ll count = 0;

    sort(num, num + a - 1);

    if (a == 2)
    {
        cout << 2 - num[0] + 1;
        count++;
    }

    else
    {

        for (ll j = 0; j < a - 1; j++)
        {

            if (num[j] != (j + 1))
            {
                cout << j + 1;
                count++;
                break;
            }
        }
    }

    if (count == 0)
    {
        cout << a << endl;
    }

    return 0;
}