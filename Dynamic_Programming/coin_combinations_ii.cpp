/*
Problem: Coin Combinations II
Link: https://cses.fi/problemset/task/1636/
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

ll dp[1000005];

void solve()
{
	ll num, need;
	cin >> num >> need;
	vector<ll> vec(num);

	for (auto &it : vec)
		cin >> it;

	dp[0] = 1;
	for (ll i = 0; i < num; i++)
	{
		for (ll j = 0; j <= need; j++)
		{
			if (vec[i] <= j)
				dp[j] = (dp[j] + dp[j - vec[i]]) % modular;
		}
	}
	cout << dp[need] << endl;
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