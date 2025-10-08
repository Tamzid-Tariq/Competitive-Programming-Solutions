/*
Problem: Planets Queries I
Link: https://cses.fi/problemset/task/1750/
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
const ll INF = 1e18;

ll vertex;

ll child[32][200005];

void solve()
{
    ll queries;
    cin >> vertex >> queries;

    for (ll i = 1; i <= vertex; i++)
    {
        cin >> child[0][i];
    }

    for (ll bit = 1; bit <= 30; bit++)
    {
        for (ll j = 1; j <= vertex; j++)
        {
            child[bit][j] = child[bit - 1][child[bit - 1][j]];
            // cout<<pow(2,bit)<<"th child of "<<j<<" is "<<child[j][bit]<<" \n";
        }
    }

    while (queries--)
    {
        ll node, times;
        cin >> node >> times;

        for (ll i = 0; i < 31; i++)
        {
            if ((1LL << i) & times)
            {
                node = child[i][node];
            }
        }
        cout << node << endl;
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