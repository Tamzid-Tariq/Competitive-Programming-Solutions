/*
Problem: SOS Bit Problem
Link: https://cses.fi/problemset/task/1654/
Author: Tamzid Tariq
Date: 2026-03-09
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

const ll N = (1LL << 20);
int subset[N + 6], superset[N + 6];

void solve()
{
    ll num;
    cin >> num;

    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
        subset[it]++;
        superset[it]++;
    }

    for (ll j = 0; j < 21; j++)
    {
        for (ll i = 1; i <= N; i++)
        {
            if (i & (1LL << j))
                subset[i] += subset[i ^ (1LL << j)];
        }
    }

    for (ll j = 0; j < 21; j++)
    {
        for (ll i = N; i >= 1; i--)
        {
            if (!(i & (1LL << j)) && (i ^ (1LL << j)) <= N)
                superset[i] += superset[i ^ (1LL << j)];
        }
    }

    for (ll i = 0; i < num; i++)
    {
        cout << subset[vec[i]] << " " << superset[vec[i]] << " " << num - subset[(((1LL << 20) - 1) ^ vec[i])] << endl;
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