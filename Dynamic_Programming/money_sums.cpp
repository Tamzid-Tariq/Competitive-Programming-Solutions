/*
Problem: Money Sums
Link: https://cses.fi/problemset/task/1745/
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

void solve()
{
    ll num;
    cin >> num;
    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;
    set<ll> s;
    for (ll i = 0; i < num; i++)
    {
        set<ll> temp;
        temp.insert(vec[i]);
        for (auto it : s)
            temp.insert(it + vec[i]);
        for (auto it : temp)
            s.insert(it);
    }
    cout << s.size() << endl;
    for (auto it : s)
        cout << it << " ";
    cout << endl;
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