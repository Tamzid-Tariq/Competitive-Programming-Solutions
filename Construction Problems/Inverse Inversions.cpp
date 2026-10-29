/*
Problem: Inverse Inversions
Link: https://cses.fi/problemset/task/2214/
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
	ll num, need;
	cin >> num >> need;

	ll start = 1, end = num;

	for (ll i = 0; i < num; i++)
	{
		if (end - start <= need)
		{
			need -= end - start;
			cout << end << " ";
			end--;
		}
		else
		{
			cout << start << " ";
			start++;
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