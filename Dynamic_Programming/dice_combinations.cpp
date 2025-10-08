/*
Problem: Dice Combinations
Link: https://cses.fi/problemset/task/1633/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;
using ull = unsigned long long int;
using namespace std;
const ll MOD = 1e9 + 7;

ll ans[1000006];

void precalc()
{
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 1;
	ans[4] = 1;
	ans[5] = 1;
	ans[6] = 1;
	for (ll i = 2; i <= 1000000; i++)
	{
		ll store = 0;
		for (ll j = 1; j <= 6; j++)
		{
			if (j > i)
				break;

			
			store += (ans[i - j]) % MOD;
			store = store % MOD;
			if (store < 0)
				store += MOD;
		}
		ans[i] += store; // cout<<i<<" "<<ans[i]<<endl;
	}
}

void solve()
{
	ll num;
	cin >> num;

	precalc();
	cout << ans[num] << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	n = 1;
	// cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		// cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}