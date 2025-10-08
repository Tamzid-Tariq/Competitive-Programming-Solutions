/*
Problem: Subtree Queries
Link: https://cses.fi/problemset/task/1137/
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

ll num,queries;
vector<vector<ll>>adj;
vector<ll>val,in,out;
ll timer=0;

void dfs(ll node,ll par)
{
    in[node]=timer;

    for(auto it:adj[node])
    {
        if(it==par)continue;
        timer++;
        dfs(it,node);
    }
    out[node]=timer;
}

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
        if (end - start == 1 )
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
    
    cin>>num>>queries;

    val.resize(num),adj.resize(num),in.resize(num),out.resize(num);
    for(auto &it:val)cin>>it;

    for(ll i=1;i<num;i++)
    {
        ll to,from;
        cin>>to>>from;

        to--,from--;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    dfs(0,-1);
    vector<ll>vec(num);
    for(ll i=0;i<num;i++)
    {
        vec[in[i]]=val[i];
    }

    segtree ST;
    ST.initialize(num);
    ST.build(vec);

    while(queries--)
    {
        ll type;
        cin>>type;

        if(type==1)
        {
            ll node,value;
            cin>>node>>value;
            node--;

            ST.update(value,in[node]);
        }
        else
        {
            ll node;
            cin>>node;
            node--;

            cout<<ST.query(in[node],out[node])<<endl;
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