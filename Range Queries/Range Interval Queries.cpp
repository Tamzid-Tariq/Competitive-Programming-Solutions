/*
Problem: Range Interval Queries
Link: https://cses.fi/problemset/task/3163/
Author: Tamzid Tariq
Date: 2025-12-04
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
template <class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve()
{
    ll num, queries;
    cin >> num >> queries;

    vector<ll>vec(num);
    
    for (auto &it : vec)
    {
        cin >> it;
    }

    vector<tuple<ll,ll,ll>>start[num],end[num];

    vector<ll>ans(queries);

    for (ll j = 0; j < queries; j++)
    {
        ll begins, ends, low, high;
        cin >> begins >> ends >> low >> high;

        start[--begins].push_back({low,high,j});
        end[--ends].push_back({low,high,j});  
    }

    ordered_set<pair<ll,ll>>os;

    for(ll i=0;i<num;i++)
    {
        for(auto [begin,ends,id]:start[i])
        {
            ans[id]+= os.order_of_key({begin,-INF});
            ans[id]-=os.order_of_key({ends,INF});
        }
        os.insert({vec[i],i});
        for(auto [begin,ends,id]:end[i])
        {
            ans[id]-= os.order_of_key({begin,-INF});
            ans[id]+=os.order_of_key({ends,INF});
        }
    }

    for(auto it:ans)cout<<it<<"\n";
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