/*
Problem: Dynamic Range Minimum Queries
Link: https://cses.fi/problemset/task/1649/
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

struct segtree
{
	ll siz = 1;
	vector<ll> val;

	void initialize(ll num)
	{
		while (siz < num)
			siz *= 2;
		val.assign(2 * siz + 1, LLONG_MAX);
	}

	ll merge(ll val1, ll val2)
	{
		return min(val1, val2);
	}

	void build(vector<ll> &vec, ll parent, ll start, ll end)
	{
		if (end - start == 1)
		{
			if (start < vec.size())
				val[parent] = vec[start];
			return;
		}
		ll mid = (start + end) / 2;
		// if (mid > vec.size())
		build(vec, 2 * parent + 1, start, mid);
		// else
		build(vec, 2 * parent + 2, mid, end);
		val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
	}

	void build(vector<ll> &vec)
	{
		build(vec, 0, 0, siz);
	}

	void update(ll value, ll ind, ll parent, ll start, ll end)
	{
		if (end - start == 1)
		{
			val[parent] = value;
			return;
		}

		ll mid = (start + end) / 2;

		if (ind < mid)
			update(value, ind, 2 * parent + 1, start, mid);
		else
			update(value, ind, 2 * parent + 2, mid, end);

		val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2]);
	}

	void update(ll value, ll ind)
	{
		update(value, ind, 0, 0, siz);
	}

			

	ll query(ll lo, ll hi, ll parent, ll start, ll end)
	{
		if (lo <= start && end - 1 <= hi)
			return val[parent];

		if (start > hi || end <= lo)
			return LLONG_MAX;

		ll mid = (start + end) / 2;

		return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end));
	}

	ll query(ll lo, ll hi)
	{
		return query(lo, hi, 0, 0, siz);
	}
};

void solve()
{
	ll num, queries;
	cin >> num >> queries;

	vector<ll> vec(num);
	for (auto &it : vec)
		cin >> it;

	struct segtree st;
	st.initialize(num);
	st.build(vec);

	// for(ll i=0;i<num;i++)st.update(vec[i],i),cout<<st.query(i-1,i);

	while (queries--)
	{
		ll op;
		cin >> op;
		if (op == 2)
		{
			ll lo, hi;
			cin >> lo >> hi;
			cout << st.query(lo-1, hi -1) << endl;
		}
		else
		{
			ll pos,val;
			cin>>pos>>val;

			st.update(val,pos-1);
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