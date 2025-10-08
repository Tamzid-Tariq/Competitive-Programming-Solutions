/*
Problem: Room Allocation
Link: https://cses.fi/problemset/task/1164/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;

void solve()
{
    ll num;
    cin >> num;
    multimap<pair<ll, ll>, ll> mp;
    for (int i = 0; i < num; i++)
    {
        ll arrive, depart;
        cin >> arrive >> depart;
        mp.insert({{arrive, depart}, i});
    }
    vector<ll> ans(num);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll room = 1;
    for (auto it : mp)
    {
        ll reachtime = it.first.first;
        ll leave = it.first.second;
        ll index = it.second;

        if (pq.empty())
        {
            pq.push({leave, room});
            ans[index] = room;
        }
        else
        {
            auto it = pq.top();
            if (reachtime > it.first)
            {

                pq.push({leave, it.second});
                ans[index] = it.second;
                pq.pop();
            }
            else
            {
                room++;
                pq.push({leave, room});
                ans[index] = room;
            }
        }
    }
    cout << room << endl;
    for (auto it : ans)
    {
        cout << it << " ";
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
        solve();
    }
    return 0;
}