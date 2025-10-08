/*
Problem: Permutations
Link: https://cses.fi/problemset/task/1070/
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

    int str[a + 1];

    if (a == 1)
    {
        cout << "1";
    }

    else if (a == 2 || a == 3)
    {
        cout << "NO SOLUTION";
    }

    else if (a % 2 == 0)
    {
        for (ll i = 2; i <= a; i += 2)
        {

            cout << i << " ";
        }

        for (ll i = 1; i < a; i += 2)
        {
            cout << i << " ";
        }
    }

    else if (a % 2)
    {

        for (ll i = a - 1; i > 1; i -= 2)
        {
            cout << i << " ";
        }

        for (ll i = a; i > 0; i -= 2)
        {
            cout << i << " ";
        }
    }

    return 0;
}