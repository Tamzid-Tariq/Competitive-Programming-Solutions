/*
Problem: Minimal Grid Path
Link: https://cses.fi/problemset/task/3359/
Author: Tamzid Tariq
Date: 2025-10-08
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

void solve()
{
    ll num;
    cin >> num;

    vector<string> vec(num);
    for (auto &it : vec)
        cin >> it;

    cout << vec[0][0];

    vector<vector<bool>> visited(num + 1, vector<bool>(num + 1));
    visited[0][0] = 1;

    for (ll i = 1; i < 2 * num - 1; i++)
    {
        ll mini = 25;
        vector<tuple<ll, ll, ll>> all;

        for (ll row = 0; row <= i; row++)
        {
            ll col = i - row, lastx = row - 1, lasty = col - 1;

            if (min(row, col) < 0 || max(row, col) >= num)
                continue;

            if (lastx >= 0 && visited[lastx][col])
            {
                mini = min(mini, (ll)vec[row][col] - 'A');
                all.push_back({vec[row][col], row, col});
            }

            else if (lasty >= 0 && visited[row][lasty])
            {
                mini = min(mini, (ll)vec[row][col] - 'A');
                all.push_back({vec[row][col], row, col});
            }
        }

        cout << (char)(mini + 'A');

        for (auto &[it, lit, kit] : all)
        {
            if (it - 'A' == mini)
                visited[lit][kit] = 1;
        }
    }

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