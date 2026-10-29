/*
Problem: Increasing Array Queries
Link: https://cses.fi/problemset/task/2416/
Author: Tamzid Tariq
Date: 2025-12-07
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

struct sparsetable
{
    vector<vector<ll>> lookup;
    vector<ll> arr;
    ll times = 1, siz;

    void initialize(ll num)
    {
        siz = num;
        arr.resize(num);
        times = log2(num);
        lookup.resize(num, vector<ll>(times + 1));
    }

    ll merge(ll val1, ll val2)
    {
        return max(val1, val2);
    }

    void build(vector<ll> &vec)
    {
        for (ll i = 0; i < siz; i++)
            lookup[i][0] = vec[i];

        for (ll j = 1; j <= times; j++)
        {
            for (ll i = 0; i + (1LL << j) <= siz; i++)
                lookup[i][j] = merge(lookup[i][j - 1], lookup[i + (1LL << (j - 1))][j - 1]);
        }
    }

    ll query(ll lo, ll hi)
    {
        ll j = log2(hi - lo + 1);

        return merge(lookup[lo][j], lookup[hi - (1LL << j) + 1][j]);
    }
};

void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll> vec(num + 1), prefsum(num + 2), nxt_big(num + 2, num + 1), ans(num + 2, 0);
    for (ll i = 1; i <= num; i++)
    {
        cin >> vec[i];
        prefsum[i] = prefsum[i - 1] + vec[i];
    }

    stack<ll> st;
    for (ll i = num; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] <= vec[i])
            st.pop();

        if (st.empty())
            nxt_big[i] = num + 1;
        else
            nxt_big[i] = st.top();

        st.push(i);

        ll times = nxt_big[i] - i;
        ans[i] = (vec[i] * times) - (prefsum[nxt_big[i] - 1] - prefsum[i - 1]) + ans[nxt_big[i]];
    }

    // for(ll i=1;i<=num;i++)cout<<ans[i]<<" ";
    // cout<<endl;

    sparsetable ST;
    ST.initialize(num + 2);
    ST.build(nxt_big);

    for (ll i = 1; i <= queries; i++)
    {
        ll start, end;
        cin >> start >> end;

        ll result = ans[start];

        ll lo = start, hi = end, got = end;
        while (lo <= hi)
        {
            ll mid = (lo + hi) >> 1LL;

            if (ST.query(start, mid) > end)
            {
                got = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        ll extra = ans[nxt_big[got]] + (vec[got] * (nxt_big[got]-got)) -(prefsum[nxt_big[got]-1] - prefsum[got-1]); 
        extra -=(vec[got] * (end-got+1)) -(prefsum[end] - prefsum[got-1]);
        
        // cout<<result<<" "<<extra<<" "<<got<<endl;

        cout << result - extra << endl;
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