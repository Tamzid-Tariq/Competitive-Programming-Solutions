/*
Problem: Palindrome Queries
Link: https://cses.fi/problemset/task/2420/
Author: Tamzid Tariq
Date: 2025-11-30
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
 
const ll base = 131;

ll modularBinaryExponentiation(ll base, ll exponent)
{
    if (exponent <= 0)
        return 1;
   

    ll result = modularBinaryExponentiation(base, exponent / 2);
    result %= modular;

    if (exponent & 1)
        return (((((result * result)) % modular) * base) % modular);
    else
        return ((result * result) % modular);
}

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

ll subtract(ll val1, ll val2)
{
    ll result = modular + ((val1 % modular) - (val2 % modular));
    return result % modular;
}

ll multiply(ll val1, ll val2)
{
    ll result = (val1 % modular) * (val2 % modular);
    return result % modular;
}

ll divide(ll val1, ll val2)
{
    ll denominator = modularBinaryExponentiation(val2 % modular, modular - 2) % modular;
    ll result = multiply(val1, denominator);

    return result % modular;
}

 
struct node
{
    ll hash;
};
 
struct segtree
{
    ll siz = 1;
    vector<node> val;
 
    node makenode(ll val)
    {
        node ret;
        ret.hash = val;
 
        return ret;
    }
 
    void initialize(ll num)
    {
        while (siz < num)
            siz *= 2;
        val.assign(2 * siz + 1, makenode(0));
    }
 
    node merge(node val1, node val2, ll len)
    {
        node ret;
        ret.hash=0LL;

        ret.hash = add(val1.hash, multiply(modularBinaryExponentiation(base, len), val2.hash));
        
        // cout<<val1.hash<<" & "<<val2.hash<<" --- "<<len<<" == "<<ret.hash<<endl;

        return ret;
    }
 
    void build(vector<ll> &vec, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            if (start < vec.size())
                val[parent] = makenode(vec[start]);
            return;
        }
 
        ll mid = (start + end) / 2;
 
        build(vec, 2 * parent + 1, start, mid);
        build(vec, 2 * parent + 2, mid, end);
 
        val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2], mid - start);
    }
 
    void build(vector<ll> &vec)
    {
        build(vec, 0, 0, siz);
    }
 
    void update(ll value, ll ind, ll parent, ll start, ll end)
    {
        if (end - start == 1)
        {
            val[parent] = makenode(value);
            return;
        }
 
        ll mid = (start + end) / 2;
 
        if (ind < mid)
            update(value, ind, 2 * parent + 1, start, mid);
        else
            update(value, ind, 2 * parent + 2, mid, end);
 
        val[parent] = merge(val[2 * parent + 1], val[2 * parent + 2], mid - start);
    }
 
    void update(ll val, ll ind)
    {
        update(val, ind, 0, 0, siz);
    }
 
    node query(ll lo, ll hi, ll parent, ll start, ll end)
    {
        if (lo <= start && end - 1 <= hi)
            return val[parent];
 
        if (start > hi || end <= lo)
            return makenode(0);
 
        ll mid = (start + end) / 2;
        ll left_len = min(mid, hi + 1) - max(start, lo);

        return merge(query(lo, hi, 2 * parent + 1, start, mid), query(lo, hi, 2 * parent + 2, mid, end),left_len);
    }
 
    ll query(ll lo, ll hi)
    {
        node got = query(lo, hi, 0, 0, siz);
 
        return got.hash;
    }
};
 
void solve()
{
    ll num, queries;
    cin >> num >> queries;
 
    string s;
    cin >> s;
 
    vector<ll> vec(num);
 
    for (ll i = 0; i < num; i++)
        vec[i] = 1 + (s[i] - 'a');
 
    segtree ST;
    ST.initialize(num+1);
    ST.build(vec);
 
    vector<ll> vecb = vec;
    reverse(vecb.begin(), vecb.end());
    
    segtree ST2;
    ST2.initialize(num+1);
    ST2.build(vecb);
 
    while (queries--)
    {
        ll op;
        cin >> op;
 
        if (op == 1)
        {
            ll where;
            char ch;
            cin >> where >> ch;
            where--;
 
            vec[where] = 1 + (ch - 'a');
            vecb[num - 1 - where] = vec[where];
            ST.update(vec[where], where);
            ST2.update(vecb[num - 1 - where], num - 1 - where);
        }
        else
        {
            ll start, end;
            cin >> start >> end;
            start--, end--;
 
            cout << (ST.query(start, end) == ST2.query(num - end - 1, num - 1 - start) ? "YES" : "NO") << endl;

            // for(ll i=start;i<=end;i++)cout<<ST.query(i,i)<<" "; cout<<" -> " <<ST.query(start,end)<<endl;
            // for(ll i=num-end-1;i<=num-1-start;i++)cout<<vecb[i]<<"="<<ST2.query(i,i)<<" "; cout<<" -> " <<ST2.query(num-1-end,num-1-start)<<endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // init();
 
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