/*
Problem: K Subset Xors
Link: https://cses.fi/problemset/task/3192/
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

const ll B = 30;

struct Basis
{
	ll basis[B], id[B], sz;
	void clear()
	{
		memset(basis, 0, sizeof(basis));
		memset(id, 0, sizeof(id));
		sz = 0;
	}
	Basis()
	{
		clear();
	}
	void insert(ll x, ll j)
	{
		for (ll i = B - 1; i >= 0; i--)
		{
			if ((x >> i) & 1)
			{
				if (basis[i])
				{
					if (j > id[i])
					{
						swap(basis[i], x);
						swap(id[i], j);
					}
					x ^= basis[i];
				}
				else
				{
					basis[i] = x;
					id[i] = j;
					sz++;
					break;
				}
			}
		}
	}
	// is there any subset having xor=x
	bool can(ll x)
	{
		for (ll i = B - 1; i >= 0; i--)
		{
			x = min(x, x ^ basis[i]);
		}
		return x == 0;
	}
	// max subset xor after xoring with x
	ll max_xor(ll x = 0, ll l = 0)
	{
		for (ll i = B - 1; i >= 0; i--)
		{
			if (id[i] >= l)
				x = max(x, x ^ basis[i]);
		}
		return x;
	}
	// kth smallest xor, 1st is 0
	ll kth(ll k)
	{
		if ((k < 1) || ((1 << sz) < k))
		{
			return -1;
		}
		ll x = 0;
		ll cnt = (1 << sz);
		for (ll i = B - 1; i >= 0; i--)
		{
			if (basis[i])
			{
				if (k > (cnt >> 1))
				{
					// set the ith bit
					if (!((x >> i) & 1))
					{
						x ^= basis[i];
					}
					k -= (cnt >> 1);
				}
				else
				{
					// unset the ith bit
					if ((x >> i) & 1)
					{
						x ^= basis[i];
					}
				}
				cnt >>= 1;
			}
		}
		return x;
	}
};
// numof occ of every xor=2^ (n−sz)
//  for l, r queries:
//  quer[r].pushback({l, i}), traverse 1 to n

void solve()
{
	ll num, k;
	cin >> num >> k;

	vector<ll> vec(num);
	for (auto &it : vec)
		cin >> it;

	Basis B;

	for (int i = 0; i < num; i++)
		B.insert(vec[i], i);

	ll now = 0, pos = 1, times = (1LL << (num - B.sz));

	while (now < k)
	{
		ll here = min(times, k - now);
		for (ll j = 0; j < here; j++)
		{
			cout << B.kth(pos) << " ";
		}
		now += here;
		pos++;
	}
	cout << endl;
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