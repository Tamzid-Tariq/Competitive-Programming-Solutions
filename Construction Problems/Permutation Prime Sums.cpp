/*
Problem: Permutation Prime Sums
Link: https://cses.fi/problemset/task/3423/
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

vector<bool> primes(200005, true);

void precompute()
{

	primes[1] = false;

	for (ll i = 2; i <= 200000; i++)
	{
		if (primes[i])
			for (ll j = 2 * i; j <= 200000; j += i)
				primes[j] = false;
	}
}

//7
// 1 2 3 4 5 6 7 
// 1 3 2 7 6 5 4 


void solve()
{
	ll num;
	cin >> num;

	for (ll i = 1; i <= num; i++)
		cout << i << " ";
	cout << endl;

	function<void(ll)> go = [&](ll val)
	{
		if (val == 0)
			return;

		ll got = 0;
		for (ll j = 1;; j++)
			if (primes[val + j])
			{
				got = j;
				break;
			}

		go(got - 1);

		for (ll j = val; j >= got; j--)
			cout << j << " ";

		return;
	};

	go(num);
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	precompute();

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