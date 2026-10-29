/*
Problem: Fixed-Length Paths I
Link: https://cses.fi/problemset/task/2080/
Author: Tamzid Tariq
Date: 2025-10-27
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
 
const int N = 200005;
ll ans = 0;
int K; // path length k that we r searching
 
struct CentroidDecomposition
{
    vector<vector<int>> adj;
    vector<bool> done;
    vector<int> parent, subsize, cnt;
    int root, max_depth = 1;
 
    CentroidDecomposition(vector<vector<int>> &tree) : adj(tree)
    {
        int siz = adj.size();
        done.assign(siz, false);
        parent.assign(siz, -1);
        subsize.assign(siz, 0);
        cnt.assign(N, 0);
        cnt[0]=1;
        decompose(0);
    }
 
    int get_subtree_size(int node, int parent = -1)
    {
        subsize[node] = 1;
 
        for (auto it : adj[node])
        {
            if (it == parent || done[it])
                continue;
 
            subsize[node] += get_subtree_size(it, node);
        }
        return subsize[node];
    }
 
    int get_centroid(int node, int need, int parent = -1)
    {
        ll ret = node;
 
        for (auto it : adj[node])
        {
            if (it != parent && !done[it] && subsize[it] >= need)
                return get_centroid(it, need, node);
        }
        return ret;
    }
 
    void get_cnt(int node, int parent, bool filling, int depth = 1)
    {
        if (depth > K)
            return;
        max_depth = max(max_depth, depth);
 
        if (filling)
            cnt[depth]++;
        else
            ans += (1LL) *cnt[K - depth];
 
        for (auto it : adj[node])
            if (!done[it] && it != parent)
                get_cnt(it, node, filling, depth + 1);
    }
 
    void decompose(int node = 0)
    {
        int centroid = get_centroid(node, get_subtree_size(node) >> 1LL);
 
        done[centroid] = 1;
        max_depth = 0;
 
        for (auto it : adj[centroid])
        {
            if (!done[it])
            {
                get_cnt(it, centroid, false);
                get_cnt(it, centroid, true);
            }
        }
 
        fill(cnt.begin() + 1, cnt.begin() + max_depth + 1, 0);
        
        for (auto it : adj[centroid])
            if (!done[it])
                decompose(it);
    }
};
 
void solve()
{
    ll num;
    cin>>num>>K;
 
    vector<vector<int>>adj(num);
    for(ll i=1;i<num;i++)
    {
        int from,to;
        cin>>from>>to;
 
        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }
 
    CentroidDecomposition cd(adj);
    // cd.decompose();
 
    cout<<ans<<endl;
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