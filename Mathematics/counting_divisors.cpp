/*
Problem: Counting Divisors
Link: https://cses.fi/problemset/task/1713/
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

void precalculate(ll n)

{

    for (ll i = 2; i <= n; i++)

    {

        ll start = i;

        while (start <= n)

        {

            answer[start]++;

            start += i;
        }
    }
}

void solve()

{

    ll number;

    cin >> number;

    cout << answer[number] + 1 << endl;
}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    precalculate(1000000);

    ll n;

    n = 1;

    cin >> n;

    for (ll i = 1; i <= n; i++)

    {

        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}