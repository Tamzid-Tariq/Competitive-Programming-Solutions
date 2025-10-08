/*
Problem: Josephus Problem II
Link: https://cses.fi/problemset/task/2163/
Author: Tamzid Tariq
Date: 2025-10-08
Status: Accepted ✓
*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using ll = long long int;
using ull = unsigned long long int;
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maximum = 1e9 + 7;

void solve()
{    
    ll number,interval;
    cin>>number>>interval;
    ordered_set<ll>children;
    for(ll i=1;i<=number;i++){
        children.insert(i);
    }
    ll startPosition=0;
    while(children.size()>0){
        startPosition%=children.size();
        ll positionToRemove=(startPosition+interval)%children.size();
        startPosition=positionToRemove;
        auto it=children.find_by_order(positionToRemove);
        cout<<*it<<" ";
        children.erase(it);
    }
   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*ll n;
    cin >> n;
    while (n--)
    {*/
        solve();
    //}
    return 0;
}