/*
Problem: Range Updates and Sums
Link: https://cses.fi/problemset/task/1735/
Author: Tamzid Tariq
Date: 2025-12-23
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

struct node
{
    ll type;
    ll lazy;
    ll value;
};

node makenode(ll val)
{
    node ret;
    ret.lazy = ret.type = 0;
    ret.value = val;

    return ret;
}

struct lazysegtree
{

    ll siz;
    vector<node> tree;

    ll merge(ll a, ll b)
    {
        return (a + b);
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
        if (tree[parent].type == 0 || end == start + 1)
            return;

        ll mid = (start + end) / 2;

        if (tree[parent].type == 2)
        {
            tree[2 * parent + 1].type = tree[2 * parent + 2].type = 2;
            tree[2 * parent + 1].lazy = tree[2 * parent + 2].lazy = tree[parent].lazy;

            tree[2 * parent + 1].value = tree[parent].lazy * (mid - start);
            tree[2 * parent + 2].value = tree[parent].lazy * (end - mid);
        }

        else
        {
            if(tree[2*parent+1].type != 2)
            tree[2 * parent + 1].type = 1;

            if(tree[2*parent+2].type != 2)
            tree[2 * parent + 2].type =1;

            tree[2 * parent + 1].lazy += tree[parent].lazy;
            tree[2 * parent + 2].lazy += tree[parent].lazy;;

            tree[2 * parent + 1].value += tree[parent].lazy * (mid - start);
            tree[2 * parent + 2].value += tree[parent].lazy * (end - mid);
        }

        tree[parent].type = 0;
        tree[parent].lazy = 0;
    }

    void update(ll value, ll type, ll lo, ll hi)
    {
        update(lo, hi, value, type, 0, 0, siz);
    }

    void update(ll lo, ll hi, ll val, ll type, ll parent, ll start, ll end)
    {
        push(parent, start, end);

        if (start > hi || end <= lo)
            return;

        if (start >= lo && end - 1 <= hi)
        {
            if (type == 1)
            {
                if (tree[parent].type != 2)
                    tree[parent].type = 1;
                tree[parent].lazy += val;
                tree[parent].value += val * (end - start);
            }
            else
            {
                tree[parent].type = 2;
                tree[parent].lazy = val;
                tree[parent].value = val * (end - start);
            }
        }
        else
        {
            ll mid = (start + end) / 2;
            update(lo, hi, val, type, 2 * parent + 1, start, mid);
            update(lo, hi, val, type, 2 * parent + 2, mid, end);

            tree[parent].type = 0;
            tree[parent].lazy = 0;
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
            return 0LL;

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
    ST.initialize(num + 1);
    ST.build(vec);

    for (ll i = 0; i < queries; i++)
    {
        ll type;
        cin >> type;

        if (type == 3)
        {
            ll start, end;
            cin >> start >> end;

            cout << ST.get(start - 1, end - 1) << endl;
        }
        else
        {
            ll start, end, val;
            cin >> start >> end >> val;

            ST.update(val, type, start - 1, end - 1);
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