/*
Problem: New Roads Queries
Link: https://cses.fi/problemset/task/2101/
Author: Tamzid Tariq
Date: 2026-02-17
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

struct dsu
{
    vector<ll> parents;
    vector<ll> siz;
    vector<vector<ll>> queries; // Replaced std::set with std::vector

    void init(ll len)
    {
        parents.resize(len);
        siz.assign(len, 1);
        queries.resize(len);
        for (ll i = 0; i < len; i++)
            parents[i] = i;
    }

    ll find_par(ll node)
    {
        if (parents[node] == node) return node;
        return parents[node] = find_par(parents[node]); // Path compression
    }

    // Pass the question array and result array so we can resolve queries inside add()
    void add(ll node1, ll node2, ll day, vector<ll>& result, const vector<pair<ll, ll>>& question)
    {
        ll u = find_par(node1);
        ll v = find_par(node2);

        if (u == v) return;

        // 1. SMALL-TO-LARGE FOR QUERIES: Always iterate the smaller query list
        if (queries[u].size() > queries[v].size())
        {
            swap(u, v);
        }

        for (ll q : queries[u])
        {
            if (result[q] != -1) continue; // Query already answered previously

            // Find where both endpoints of this query currently belong
            ll par_x = find_par(question[q].first);
            ll par_y = find_par(question[q].second);

            // If the endpoints belong exactly to the two components we are merging right now
            if ((par_x == u && par_y == v) || (par_x == v && par_y == u))
            {
                result[q] = day; // Solved!
            }
            else
            {
                // Not solved yet, carry the query over to the merged component
                queries[v].push_back(q);
            }
        }
        
        // Free the old vector to save memory
        queries[u].clear();

        // 2. UNION BY SIZE FOR DSU GRAPH
        if (siz[u] > siz[v])
        {
            parents[v] = u;
            siz[u] += siz[v];
            
            // 'u' is the new graph root, but 'v' holds the merged queries. 
            // We swap them so the queries sit at the new root.
            swap(queries[u], queries[v]);
        }
        else
        {
            parents[u] = v;
            siz[v] += siz[u];
            // 'v' is the new graph root, and it already holds the merged queries.
        }
    }
};

void solve()
{
    ll num, edges, queries_cnt;
    cin >> num >> edges >> queries_cnt;

    vector<pair<ll, ll>> all(edges);
    for (auto &[u, v] : all)
    {
        cin >> u >> v;
        u--, v--; // 0-based indexing
    }

    vector<pair<ll, ll>> question(queries_cnt);
    vector<ll> result(queries_cnt, -1);

    dsu DSU;
    DSU.init(num);

    for (ll i = 0; i < queries_cnt; i++)
    {
        ll from, to;
        cin >> from >> to;
        from--, to--;

        question[i] = {from, to};

        if (from == to)
        {
            result[i] = 0;
        }
        else
        {
            // Insert the query into BOTH endpoints' vectors initially
            DSU.queries[from].push_back(i);
            DSU.queries[to].push_back(i);
        }
    }

    for (ll i = 0; i < edges; i++)
    {
        auto [node1, node2] = all[i];
        DSU.add(node1, node2, i + 1, result, question);
    }

    for (auto it : result)
        cout << it << '\n';
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}