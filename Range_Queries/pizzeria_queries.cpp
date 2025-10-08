/*
Problem: Pizzeria Queries
Link: https://cses.fi/problemset/task/2206/
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
        val.assign(2 * siz + 1, LLONG_MAX);
    }
 
    ll merge(ll val1, ll val2)
    {
        return min(val1,val2);
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
    ll num,query;
    cin>>num>>query;

    vector<ll>vec(num);
    
    for(ll i=0;i<num;i++)
    {
        cin>>vec[i];
        vec[i]+=i;
    }

    segtree ST;
    ST.initialize(num);
    ST.build(vec);

    for(ll i=num-1;i>=0;i--)
    {
        vec[i]-=i;
        vec[i]+=(num-1-i);
    }
    segtree ST2;
    ST2.initialize(num);
    ST2.build(vec);

    while(query--)
    {
        ll type;
        cin>>type;

        if(type==1)
        {
            ll pos,val;
            cin>>pos>>val;

            pos--;

            ST.update(val+pos,pos);
            ST2.update(val+(num-1-pos),pos);
        }

        else
        {
            ll pos;
            cin>>pos;
            pos--;

            ll ans1=LLONG_MAX,ans2=LLONG_MAX;
            if(pos)ans1=ST2.query(0,pos)-(num-1-pos);
            if(pos<num-1)ans2=ST.query(pos,num-1)-pos;

            // cout<<ans1<<" "<<ans2<<" ->";
            cout<<min(ans1,ans2)<<endl;
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