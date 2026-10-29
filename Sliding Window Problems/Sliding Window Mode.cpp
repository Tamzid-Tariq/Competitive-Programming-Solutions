/*
Problem: Sliding Window Mode
Link: https://cses.fi/problemset/task/3224/
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

void solve()
{
    ll num, k;
    cin >> num >> k;

    vector<ll> vec(num + 1);
    for (ll i = 1; i <= num; i++)
    {
        cin >> vec[i];
        vec[i] *= -1;
    }

    map<ll, ll> times;
    set<pair<ll, ll>> all;

    for (ll i = 1; i <= num; i++)
    {
        times[vec[i]]++;

        if(times[vec[i]]>1)
        {
            all.erase(all.find({times[vec[i]]-1,vec[i]}));
        }

        all.insert({times[vec[i]],vec[i]});

        if(i>=k)
        {
            cout<<abs(all.rbegin()->second)<<" ";

            all.erase(all.find({times[vec[i+1-k]],vec[i+1-k]}));
            times[vec[i+1-k]]--;
            if(times[vec[i+1-k]])all.insert({times[vec[i+1-k]],vec[i+1-k]});
        }
    }
    cout<<endl;
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