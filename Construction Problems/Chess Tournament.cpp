/*
Problem: Chess Tournament
Link: https://cses.fi/problemset/task/1697/
Author: Tamzid Tariq
Date: 2026-03-11
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

	vector<ll> vec(num);
	multiset<pair<ll, ll>> ms;

	for (ll i = 0; i < num; i++)
	{
		cin >> vec[i];
		if (vec[i])
			ms.insert({vec[i], i});
	}

	ll total = accumulate(vec.begin(), vec.end(), 0LL),
	   maxi = *max_element(vec.begin(), vec.end());

	if (maxi >= num || total & 1)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	vector<pair<ll, ll>> ans;

	while (!ms.empty())
	{
		auto [need, who] = *ms.rbegin();
		ms.erase(ms.find({need, who}));

		vector<pair<ll, ll>> avail;

		while (ms.size() && need > 0)
		{
			auto [here, other] = *ms.rbegin();
			ms.erase(ms.find({here, other}));

			if (here > 1)
			{
				ans.push_back({other, who});
				avail.push_back({here - 1, other});
				need--;
			}
			else
			{
				ans.push_back({other, who});
				need--;
			}
		}

		if (need > 0)
		{
			cout << "IMPOSSIBLE\n";
			return;
		}

		for (auto [it, lit] : avail)
			ms.insert({it, lit});
	}

	cout << ans.size() << endl;
	for (auto [it, lit] : ans)
		cout << it + 1 << " " << lit + 1 << endl;
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