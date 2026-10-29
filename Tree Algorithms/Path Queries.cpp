/*
Problem: Path Queries
Link: https://cses.fi/problemset/task/1138/
Author: Tamzid Tariq
Date: 2025-10-25
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

const int N = 200005;

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
        return val1 + val2;
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
} ST;

vector<vector<int>> adj(N);
int ptr = 0, parent[N], siz[N], depth[N], in[N], nxt[N];

void dfs(ll node = 0, ll far = 0)
{
    siz[node] = 1, depth[node] = far;

    for (auto it : adj[node])
    {
        adj[it].erase(find(adj[it].begin(), adj[it].end(), node));
    }

    for (auto &it : adj[node])
    {
        parent[it] = node;
        dfs(it, far + 1);
        siz[node] += siz[it];

        if (siz[it] > siz[adj[node][0]])
            swap(it, adj[node][0]);
    }
}

void hld(ll node = 0)
{
    in[node] = ++ptr;

    for (auto it : adj[node])
    {
        nxt[it] = (it == adj[node][0] ? nxt[node] : it);
        hld(it);
    }
}

ll query(ll node1, ll node2)
{
    ll ret = 0;

    while (nxt[node1] != nxt[node2])
    {
        if (depth[nxt[node1]] > depth[nxt[node2]])
            swap(node1, node2);

        ret += ST.query(in[nxt[node2]], in[node2]);
        node2 = parent[nxt[node2]];
    }
    if (depth[node1] > depth[node2])
        swap(node1, node2);

    ret += ST.query(in[node1], in[node2]);

    return ret;
}

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    for (ll i = 0; i < num - 1; i++)
    {
        int from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    ptr = 0;
    dfs();
    hld();

    ST.initialize(ptr + 1);

    vector<ll> temp(ptr + 1);
    for (ll i = 0; i < num; i++)
        temp[in[i]] = vec[i];

    ST.build(temp);

    while (queries--)
    {
        ll type;
        cin >> type;

        if (type == 2)
        {
            ll from = 1, to;
            cin >> to;
            from--, to--;

            ll ans = query(from, to);

            cout << ans << "\n";
        }
        else
        {
            ll node, val;
            cin >> node >> val;
            node--;

            ST.update(val, in[node]);
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