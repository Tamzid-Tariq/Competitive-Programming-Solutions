/*
Problem: Nearest Smaller Values
Link: https://cses.fi/problemset/task/1645/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>

using ll = long long int;

using namespace std;

void solve()
{
    ll siz;
    cin >> siz;
    vector<ll> vec;
    stack<ll> store;
    //vector<ll> ans;
    for (ll i = 0; i < siz; i++)
    {
        ll num;
        cin >> num;
        vec.push_back(num);
        while (!store.empty())
        {
            ll q = store.top();
            if (vec[q] >= num)
            {
                store.pop();
            }
            else
            {
                 cout<<q+1<<" ";
                
                break;
            }
        }
        if (store.empty())  cout<<"0 ";
            
        store.push(i);
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