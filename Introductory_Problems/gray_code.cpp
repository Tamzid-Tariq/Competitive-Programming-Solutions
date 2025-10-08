/*
Problem: Gray Code
Link: https://cses.fi/problemset/task/2205/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    ll n;

    cin >> n;

    ll maxi = pow(2, n);

    for (ll i = 0; i < (maxi); i++)
    {

        bitset<32> number(i);

        // cout<<number<<endl;

        cout << number[n - 1];

        for (ll k = n - 2; k >= 0; k--)
        {

            cout << (number[k + 1] ^ number[k]);
        }
        cout << endl;
    }

    return 0;
}