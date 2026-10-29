/*
Problem: Mountain Range
Link: https://cses.fi/problemset/task/3314/
Author: Tamzid Tariq
Date: 2025-12-09
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
        return max(val1 , val2);
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
    ll num;
    cin>>num;
    
    vector<ll>vec(num);
    for(auto &it:vec)cin>>it;

    vector<ll>left(num,-1),right(num,num);
    stack<ll>st;

    for(ll i=0;i<num;i++)
    {
        while(!st.empty() && vec[st.top()]<vec[i])st.pop();

        if(!st.empty())left[i]=st.top();

        st.push(i);
    }
    while(!st.empty())st.pop();

    for(ll i=num-1;i>=0;i--)
    {
        while(!st.empty() && vec[st.top()]<vec[i])st.pop();

        if(!st.empty())right[i]=st.top();

        st.push(i);
    }

    vector<ll>sortedind(num);
    iota(sortedind.begin(),sortedind.end(),0LL);

    sort(sortedind.begin(),sortedind.end(),[&](ll ind1, ll ind2)
    {
        return vec[ind1]<vec[ind2];
    });

    segtree ST;
    ST.initialize(num);

    for(ll i=0;i<num;i++)
    {
        ll who=sortedind[i];
        
        ST.update(1 + ST.query(left[who]+1,right[who]-1) , who);
    }

    cout<<ST.query(0,num-1)<<endl;
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