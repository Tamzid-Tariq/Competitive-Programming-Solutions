/*
Problem: Removing Digits
Link: https://cses.fi/problemset/task/1637/
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
	ll dp[1000006];
	dp[0] = 0;
	for (ll i = 1; i < 10; i++)
	{
		dp[i] = 1;
	}
	for (ll i = 10; i <= num; i++)
	{
		string s = to_string(i);
		dp[i] = LLONG_MAX;
		ll siz = s.size();
		
		for (ll j = 0; j < siz; j++)
		{
			dp[i] = min(dp[i], dp[i - s[j] + '0'] + 1);
		}
	}
	cout << dp[num] << endl;
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