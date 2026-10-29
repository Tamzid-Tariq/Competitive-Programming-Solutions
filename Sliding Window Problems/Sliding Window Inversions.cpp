/*
Problem: Sliding Window Inversions
Link: https://cses.fi/problemset/task/3223/
Author: Tamzid Tariq
Date: 2026-02-09
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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve()
{
    ll num, k;
    cin >> num >> k;

    vector<ll> vec(num + 1);
    for (ll i = 1; i <= num; i++)
    {
        cin >> vec[i];
    }

    ll ans=0;
    ordered_set<ll>os;

    for(ll i=1;i<=num;i++)
    {
        ll inv=os.size() - os.order_of_key(vec[i]+1);
        ans+=inv;
        os.insert(vec[i]);

        if(i>=k)
        {
            cout<<ans<<" ";

            inv=os.order_of_key(vec[i+1-k]);
            ans-=inv;

            os.erase(os.find_by_order(inv));
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