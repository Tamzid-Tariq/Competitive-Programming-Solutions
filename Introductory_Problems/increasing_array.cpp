/*
Problem: Increasing Array
Link: https://cses.fi/problemset/task/1094/
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

    ll count = 0;

    ll as[a + 1];

    for (ll i = 0; i < a; i++)
    {

        cin >> as[i];

        if (i != 0 && as[i] < as[i - 1])
        {
            count += as[i - 1] - as[i];
            as[i] = as[i - 1];
        }
    }

    cout << count << endl;

    return 0;
}