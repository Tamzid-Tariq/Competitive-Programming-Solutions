/*
Problem: Increasing Subsequence
Link: https://cses.fi/problemset/task/1145/
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
	vector<ll> a(num);
	for (auto &it : a)
		cin >> it;

	multiset<ll> ms;
	for (ll i = 0; i < num; i++)
	{
		auto it = ms.lower_bound(a[i]);
		if (it == ms.end())
		{
			ms.insert(a[i]);
		}
		else
		{
			ms.erase(it);
			ms.insert(a[i]);
		}
	}
	cout << ms.size() << endl;
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