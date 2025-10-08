/*
Problem: Common Divisors
Link: https://cses.fi/problemset/task/1081/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using ll = long long int;

using ull = unsigned long long int;

using namespace std;

using namespace __gnu_pbds;

template <typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll modular = 1e9 + 7;

ll answer[1000006] = {0x0};

void solve()

{

    ll number;

    cin >> number;

    vector<ll> value(number);

    for (auto &it : value)

    {

        cin >> it;

        answer[it]++;
    }

    sort(value.begin(), value.end());

    ll maxi = value[number - 1];

    for (ll j = maxi; j >= 1; j--)

    {

        ll start = j;

        ll count = 0;

        while (start <= maxi)
        {

            count += answer[start];

            if (count > 1)
            {
                cout << j << endl;

                return;
            }

            start += j;
        }
    }

    cout << 1 << endl;
}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    ll n;

    n = 1;

    // cin >> n;

    for (ll i = 1; i <= n; i++)

    {

        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}