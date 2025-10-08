/*
Problem: Chessboard and Queens
Link: https://cses.fi/problemset/task/1624/
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

char grid[9][9];
bool placed[9][9];
ll ans = 0;

bool is_possible(ll row, ll col)
{
    if (grid[row][col] == '*' || placed[row][col])
        return false;

    for (ll i = 0; i < 8; i++)
    {
        if (placed[row][i] || placed[i][col])
            return false;
        ll diagx = row + i, diagy = col + i;
        if (diagx >= 0 && diagx < 8 && diagy >= 0 && diagy < 8)
        {
            if (placed[diagx][diagy])
                return false;
        }
        ll lowdiagx = row - i, lowdiagy = col - i;
        if (lowdiagx >= 0 && lowdiagx < 8 && lowdiagy >= 0 && lowdiagy < 8)
        {
            if (placed[lowdiagx][lowdiagy])
                return false;
        }
        if (lowdiagx >= 0 && lowdiagx < 8 && diagy >= 0 && diagy < 8)
        {
            if (placed[lowdiagx][diagy])
                return false;
        }
        if (diagx >= 0 && diagx < 8 && lowdiagy >= 0 && lowdiagy < 8)
        {
            if (placed[diagx][lowdiagy])
                return false;
        }
    }

    placed[row][col] = true;
    return true;
}

void dfs(ll row)
{
    if (row == 8)
    {
        ans++;
        // cout << ans << endl;
        return;
    }
    // cout<<row<<" ";
    for (ll i = 0; i < 8; i++)
    {
        if (is_possible(row, i))
        {
            dfs(row + 1);
            placed[row][i] = false;
        }
    }
}

void solve()
{

    for (ll i = 0; i < 8; i++)
    {
        for (ll j = 0; j < 8; j++)
        {
            cin >> grid[i][j];
        }
    }

    dfs(0);
    cout << ans << endl;
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