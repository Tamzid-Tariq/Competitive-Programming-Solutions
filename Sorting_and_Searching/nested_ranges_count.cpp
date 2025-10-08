/*
Problem: Nested Ranges Count
Link: https://cses.fi/problemset/task/2169/
Author: Tamzid Tariq
Date: 2025-10-08
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

struct segtree
{
	ll siz = 1;
	vector<ll> val;

	void initialize(ll num)
	{
		while (siz < num)
			siz *= 2;
		val.assign(2 * siz + 1, 0);
	}

	ll merge(ll val1, ll val2)
	{
		return (val1 + val2);
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

		build(vec, 2 * parent + 1, start, mid);
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

	void update(ll val, ll ind)
	{
		update(val, ind, 0, 0, siz);
	}

	ll query(ll lo, ll hi, ll parent, ll start, ll end)
	{
		if (lo <= start && end - 1 <= hi)
			return val[parent];

		if (start > hi || end <= lo)
			return 0;

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
	ll num;
	cin >> num;

	vector<tuple<ll, ll, ll>> vec(num);
	ll ind = 0;
	map<ll,ll>mp;

	for (auto &[it, lit, kit] : vec)
	{
		cin >> it >> lit;
		kit = ind++;
		mp[it]++,mp[lit]++;
	}
	ind = 1;
	
	for (auto &[it,lit] : mp)
		lit = ind++;

	for (auto &[it, lit, kit] : vec)
		it = mp[it], lit = mp[lit];

	sort(vec.begin(), vec.end(), [&](tuple<ll, ll, ll> &one, tuple<ll, ll, ll> &two)
		 {
		auto &[one1,one2,ind1]=one;
		auto &[two1,two2,ind2]=two;

		if(one1==two1)return one2<two2;
		return one1>two1; });

	segtree ST;
	ST.initialize(ind + 5);
	vector<ll> times(ind + 5), ans(num);

	for (ll i = 0; i < num; i++)
	{
		auto &[val1, val2, ind] = vec[i];
		ans[ind] = ST.query(val1, val2);
		times[val2]++;
		ST.update(times[val2], val2);
	}

	for (auto &it : ans)
		cout << it << " ";
	cout << endl;

	for (auto &[it, lit, kit] : vec)
	{
		
		if(!times[lit])continue;
		times[lit] = 0;
		ST.update(times[lit], lit);
	}

	for (ll i = num - 1; i >= 0; i--)
	{
		auto &[val1, val2, ind] = vec[i];
		ans[ind] = (num - 1 - i) - ST.query(0, val2 - 1);
		times[val2]++;
		ST.update(times[val2], val2);
	}

	for (auto &it : ans)
		cout << it << " ";
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