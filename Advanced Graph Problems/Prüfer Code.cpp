/*
Problem: Prüfer Code
Link: https://cses.fi/problemset/task/1134/
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

void solve()
{
	ll num;
	cin >> num;

	vector<ll> vec(num), what(num - 2);

	for (ll i = 0; i < num - 2; i++)
	{
		cin >> what[i];
		what[i]--;

		vec[what[i]]++;
	}

	vector<pair<ll, ll>> adj;

	// priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	multiset<pair<ll, ll>> ms;
	for (ll i = 0; i < num; i++)
		ms.insert({vec[i], i});

	for (ll pos = 0; pos < num - 1; pos++)
	{
		auto [times, node] = *ms.begin();
		ms.erase(ms.find({times, node}));

		cout << node + 1 << " " << ((pos < num - 2) ? what[pos] : ms.begin()->second) + 1 << endl;

		if (times)
			ms.insert({times - 1, node});

		if (pos < num - 2)
		{
			ms.erase(ms.find({vec[what[pos]], what[pos]}));
			vec[what[pos]]--;
			ms.insert({vec[what[pos]], what[pos]});
		}
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