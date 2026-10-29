/*
Problem: Fixed-Length Paths II
Link: https://cses.fi/problemset/task/2081/
Author: Tamzid Tariq
Date: 2025-10-28
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
int K1, K2; // path length k that we r searching

struct CentroidDecomposition
{
    vector<vector<int>> adj;
    vector<bool> done;
    vector<int> parent, subsize, cnt, totalcnt;
    int root, max_depth = 1, subtreedepth = 0;

    CentroidDecomposition(vector<vector<int>> &tree) : adj(tree)
    {
        int siz = adj.size();
        done.assign(siz, false);
        parent.assign(siz, -1);
        subsize.assign(siz, 0);
        cnt.assign(N, 0);
        totalcnt.assign(N, 0);
        totalcnt[0] = 1;
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
        if (depth > K2)
            return;
        subtreedepth = max(subtreedepth, depth);

        if (filling)
        {
            cnt[depth]++;
        }

        for (auto it : adj[node])
            if (!done[it] && it != parent)
                get_cnt(it, node, filling, depth + 1);
    }

    void decompose(int node = 0)
    {
        int centroid = get_centroid(node, get_subtree_size(node) >> 1LL);

        done[centroid] = 1;
        max_depth = 0;

        ll partialsum = 0, init = (K1==1);
        // cout<<centroid+1<<":\n";

        for (auto it : adj[centroid])
        {
            if (!done[it])
            {
                subtreedepth = 0;
                get_cnt(it, centroid, true);
                max_depth = max(max_depth, subtreedepth);

                partialsum=init;

                for(ll i=1;i<=subtreedepth;i++)
                {
                    ans+=partialsum*cnt[i];

                    if(i<K1)partialsum+=totalcnt[K1-i-1];
                    if(i<K2)partialsum-=totalcnt[K2-i];
                }

                for(ll i=1;i<=subtreedepth;i++)
                {
                    totalcnt[i]+=cnt[i];
                }

                for(ll i=K1-1;i<=K2-1 && i<=subtreedepth;i++)init+=cnt[i];

                fill(cnt.begin(),cnt.begin()+subtreedepth+1,0);
            }
        }

        fill(totalcnt.begin() + 1, totalcnt.begin() + max_depth + 1, 0);

        for (auto it : adj[centroid])
            if (!done[it])
                decompose(it);
    }
};

void solve()
{
    ll num;
    cin >> num >> K1 >> K2;

    vector<vector<int>> adj(num);
    for (ll i = 1; i < num; i++)
    {
        int from, to;
        cin >> from >> to;

        adj[--from].push_back(--to);
        adj[to].push_back(from);
    }

    CentroidDecomposition cd(adj);
    // cd.decompose();

    cout << ans << endl;
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