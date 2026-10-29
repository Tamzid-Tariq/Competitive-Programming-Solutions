/*
Problem: Distinct Values Queries II
Link: https://cses.fi/problemset/task/3356/
Author: Tamzid Tariq
Date: 2025-11-06
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
        return max(val1, val2);
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
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num + 1);
    for (ll i = 1; i <= num; i++)
        cin >> vec[i];

    vector<ll> left(num + 3), right(num + 3);

    map<ll, set<ll>> all;
    for (ll i = 1; i <= num; i++)
    {
        right[i] = num + 1;

        if (all.count(vec[i]))
        {
            ll last = *all[vec[i]].rbegin();
            left[i] = last;
            right[last] = i;
        }
        else
            left[i] = 0;

        all[vec[i]].insert(i);
    }

    segtree ST;
    ST.initialize(num + 3);
    ST.build(left);

    for (ll i = 1; i <= queries; i++)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll pos, val;
            cin >> pos >> val;

            ll earlierL = left[pos], earlierR = right[pos];
            right[earlierL] = earlierR;
            left[earlierR] = earlierL;
            ST.update(left[earlierR], earlierR);

            if (!all.count(val))
            {
                left[pos] = 0;
                right[pos] = num + 1;

                ST.update(left[pos], pos);
            }
            else
            {
                auto it = all[val].upper_bound(pos);

                ll R = num + 1, L = 0;
                if (it != all[val].end())
                    R = *it;

                if (it != all[val].begin())
                {
                    it--;
                    L = *it;
                }

                left[R] = pos;
                right[L] = pos;
                right[pos] = R;
                left[pos] = L;

                ST.update(left[R], R);
                ST.update(left[pos], pos);
            }

            all[vec[pos]].erase(pos);
            vec[pos] = val;
            all[val].insert(pos);
        }
        else
        {
            ll start, end;
            cin >> start >> end;

            if (ST.query(start, end) >= start)
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
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