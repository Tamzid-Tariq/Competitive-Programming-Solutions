/*
Problem: De Bruijn Sequence
Link: https://cses.fi/problemset/task/1692/
Author: Tamzid Tariq
Date: 2025-12-03
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

ll num, edges;
vector<vector<ll>> adj(N);
vector<ll> circuit;
vector<bool> visited(N);
vector<ll> from(N), to(N), outdegree(N), indegree(N);

void eulerpathdirected(ll start)
{
    vector<ll> path;
    path.push_back(start);

    ll current = start;
    while (!path.empty())
    {
        if (outdegree[current])
        {
            path.push_back(current);
            while (visited[adj[current].back()])
                adj[current].pop_back();

            ll edge = adj[current].back(), next = to[edge];
            visited[edge] = 1;
            outdegree[current]--, indegree[next]--;
            current = next;
        }
        else
        {
            circuit.push_back(current);
            current = path.back();
            path.pop_back();
        }
    }

    reverse(circuit.begin(), circuit.end());
}

void solve()
{
    cin >> num;

    if(num==1)
    {
        cout<<"01"<<endl;
        return;
    }

    ll edges=(1LL<<num);

    for (ll i = 0; i < edges/2; i++)
    {
        ll u = i, v =(2*i)%(1LL<<(num-1));

        from[2*i] = u;
        to[2*i] = v;

        adj[u].push_back(2*i);

        outdegree[u]++;
        indegree[v]++;

        u = i, v =(2*i + 1)%(1LL<<(num-1));

        from[2*i+1] = u;
        to[2*i+1] = v;

        adj[u].push_back(2*i+1);

        outdegree[u]++;
        indegree[v]++;
    }
    

    eulerpathdirected(0);
    
    for(ll i=0;i<num-2;i++)cout<<0;
    for (auto it : circuit)
        cout << it%2;
    cout << endl;
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