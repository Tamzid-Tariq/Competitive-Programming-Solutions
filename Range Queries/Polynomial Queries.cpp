/*
Problem: Polynomial Queries
Link: https://cses.fi/problemset/task/1736/
Author: Tamzid Tariq
Date: 2026-02-06
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

struct lazysegtree
{
    const ll NO_OPERATION = 0LL;
    const ll EMPTY = 0LL;

    struct node
    {
        ll lazy;
        ll times;
        ll value;
    };

    ll siz;
    vector<node> tree;

    ll modify(ll a, ll b, ll len, ll times)
    {
        ll ret = a + b * len + times * ((len - 1) * len) / 2;

        return ret;
    }

    ll merge(ll a, ll b)
    {
        return (a + b);
    }

    node makenode(ll val)
    {
        node ret;
        ret.lazy = ret.times = 0LL;
        ret.value = val;

        return ret;
    }

    void initialize(ll n)
    {
        siz = 1;
        while (siz < n)
            siz *= 2;
        tree.resize(2 * siz);
        tree.assign(2 * siz, makenode(0));
    }

    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                tree[parent] = makenode(vec[start]);
            return;
        }

        ll mid = (start + end) / 2;

        build(vec, 2 * parent + 1, start, mid);
        build(vec, 2 * parent + 2, mid, end);

        tree[parent] = makenode(merge(tree[2 * parent + 1].value, tree[2 * parent + 2].value));
    }

    void build(vector<ll> &vec)
    {
        build(vec, 0, 0, siz);
    }

    void push(ll parent, ll start, ll end)
    {
        if (tree[parent].lazy == 0LL || end == start + 1)
            return;

        ll mid = (start + end) / 2;

        tree[2 * parent + 1].lazy += tree[parent].lazy;
        tree[2 * parent + 1].times += tree[parent].times;
        tree[2 * parent + 1].value = modify(tree[2 * parent + 1].value, tree[parent].lazy, mid - start, tree[parent].times);

        tree[2 * parent + 2].lazy += tree[parent].lazy + (mid - start) * tree[parent].times;
        tree[2 * parent + 2].times += tree[parent].times;
        tree[2 * parent + 2].value = modify(tree[2 * parent + 2].value, tree[parent].lazy + (mid - start) * tree[parent].times, end - mid, tree[parent].times);

        tree[parent].lazy = 0LL;
        tree[parent].times = 0LL;
    }

    void update(ll value, ll lo, ll hi)
    {
        update(lo, hi, value, 0, 0, siz);
    }

    void update(ll lo, ll hi, ll val, ll parent, ll start, ll end)
    {
        push(parent, start, end);
        if (start > hi || end <= lo)
            return;

        if (start >= lo && end - 1 <= hi)
        {
            tree[parent].lazy += val;
            tree[parent].times++;
            tree[parent].value = modify(tree[parent].value, val, end - start, 1);
        }
        else
        {
            ll mid = (start + end) / 2;

            ll offset = max(0LL, mid - max(start, lo));

            update(lo, hi, val, 2 * parent + 1, start, mid);
            update(lo, hi, val + offset, 2 * parent + 2, mid, end);
            tree[parent].value = merge(tree[2 * parent + 1].value, tree[2 * parent + 2].value);
        }
    }

    ll get(ll lo, ll hi)
    {
        return get(lo, hi, 0, 0, siz);
    }

    ll get(ll lo, ll hi, ll parent, ll start, ll end)
    {
        push(parent, start, end);
        if (start > hi || end <= lo)
            return EMPTY;
        if (start >= lo && end - 1 <= hi)
            return tree[parent].value;
        ll mid = (start + end) / 2;
        ll v1 = get(lo, hi, 2 * parent + 1, start, mid);
        ll v2 = get(lo, hi, 2 * parent + 2, mid, end);
        return merge(v1, v2);
    }
};

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    lazysegtree ST;
    ST.initialize(num);
    ST.build(vec);

    for (ll i = 0; i < queries; i++)
    {
        ll type, start, end;
        cin >> type >> start >> end;

        start--, end--;

        if (type == 1)
        {
            ST.update(1, start, end);
        }
        else
        {
            cout << ST.get(start, end) << endl;
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