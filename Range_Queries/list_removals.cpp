/*
Problem: List Removals
Link: https://cses.fi/problemset/task/1749/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 10000000000LL;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    ll num;
    cin >> num;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    ordered_set os;
    for (ll i = 0; i < num; i++)
    {
        os.insert(i);
    }

    for (ll i = 0; i < num; i++)
    {
        ll val;
        cin >> val;
        val--;

        ll ind = *os.find_by_order(val);
        cout << vec[ind] << " ";
        os.erase(os.find_by_order(val));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    // cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}