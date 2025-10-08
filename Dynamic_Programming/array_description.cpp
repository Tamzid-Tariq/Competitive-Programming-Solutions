/*
Problem: Array Description
Link: https://cses.fi/problemset/task/1746/
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
	ll num, maxi;
	cin >> num >> maxi;

	vector<ll> vec(num);
	ll dp[num + 2][maxi + 2];
	memset(dp, 0LL, sizeof dp);

	for (ll i = 1; i <= num; i++)
	{
		cin >> vec[i - 1];
		if (i == 1)
		{
			if (vec[i - 1] != 0)
				dp[i][vec[i - 1]] = 1;
			else
			{
				for (ll i = 1; i <= maxi; i++)
					dp[1][i] = 1;
			}
			continue;
		}
		if (vec[i - 1] == 0)
		{
			for (ll j = 1; j <= maxi; j++)
			{
				dp[i][j] = (dp[i - 1][j]);
				if (j - 1 >= 1)
					dp[i][j] += (dp[i - 1][j - 1]);
				dp[i][j] %= modular;
				if (j + 1 <= maxi)
					dp[i][j] += (dp[i - 1][j + 1]);
				dp[i][j] %= modular;
			}
		}
		else
		{
			dp[i][vec[i - 1]] = dp[i - 1][vec[i - 1]];
			if (vec[i - 1] - 1 >= 1)
				dp[i][vec[i - 1]] += (dp[i - 1][vec[i - 1] - 1]);
			dp[i][vec[i - 1]] %= modular;
			if (vec[i - 1] + 1 <= maxi)
				dp[i][vec[i - 1]] += (dp[i - 1][vec[i - 1] + 1]);
			dp[i][vec[i - 1]] %= modular;
		}
	}
	ll ans = 0;

	for (ll i = 1; i <= maxi; i++)
	{
		// cout << dp[num][i] << " ";
		ans += dp[num][i];
		ans %= modular;
	}
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