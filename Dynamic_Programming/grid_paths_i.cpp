/*
Problem: Grid Paths I
Link: https://cses.fi/problemset/task/1638/
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

ll dp[1005][1005];

void solve()
{
	ll num;
	cin >> num;
	char grid[num][num];

	for (ll i = 0; i < num; i++)
	{
		for (ll j = 0; j < num; j++)
		{
			cin >> grid[i][j];
		}
	}
	dp[0][0] = 1;
	for (ll i = 0; i < num; i++)
	{
		for (ll j = 0; j < num; j++)
		{
			if (grid[i][j] == '*')
			{
				dp[i][j] = 0;
				continue;
			}
			if (i - 1 >= 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % modular;
			if (j - 1 >= 0)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % modular;
		}
	}
	cout << dp[num - 1][num - 1] << endl;
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