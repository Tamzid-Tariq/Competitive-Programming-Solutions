/*
Problem: Monotone Subsequences
Link: https://cses.fi/problemset/task/2215/
Author: Tamzid Tariq
Date: 2026-03-12
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

// 10 3
// 7 8 9 4 5 6 1 2 3 10
// 8 9 10 5 6 7 2 3 4 1
// 4 3 2 7 6 5 10 9 8 1

void solve()
{
	ll num, maxi;
	cin >> num >> maxi;

	ll siz1 = (num + maxi - 1) / maxi;

	if (siz1 > maxi)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}

	ll start = num - maxi + 1;

	while (start > 0)
	{
		for (ll i = 0; i < maxi; i++)
			cout << start + i << " ";

		start -= maxi;
	}

	for (ll i = 1; i <= (num % maxi); i++)
		cout << i << " ";

	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	n = 1;
	cin >> n;
	for (ll i = 1; i <= n; ++i)
	{
		// cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}