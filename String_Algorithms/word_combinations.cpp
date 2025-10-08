/*
Problem: Word Combinations
Link: https://cses.fi/problemset/task/1731/
Author: Tamzid Tariq
Date: 2025-10-08
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

const int K = 26;

struct Vertex
{
    int next[K];
    bool output = false;

    Vertex()
    {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const &s)
{
    int v = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

ll add(ll val1, ll val2)
{
    ll result = (val1 % modular) + (val2 % modular);
    return result % modular;
}

void solve()
{
    string s;
    cin >> s;

    ll num = s.size();

    ll times;
    cin >> times;

    while (times--)
    {
        string here;
        cin >> here;

        add_string(here);
    }

    vector<ll> ans(num + 1);
    ans[0] = 1;

    for (ll i = 1; i <= num; i++)
    {
        if (!ans[i - 1])
            continue;

        ll node = 0;
        for (ll j = i - 1; j < num; j++)
        {
            ll need = (s[j] - 'a');

            // cout<<node<<" "<<need<<" -> ";

            if (trie[node].next[need] == -1)
            {
                // cout<<i<<" ";
                // cout<<node<<" "<<need<<endl;

                break;
            }

            node = trie[node].next[need];

            if (trie[node].output == true)
                ans[j + 1] = add(ans[j + 1], ans[i - 1]);
        }
    }
    // for(auto it:ans)cout<<it<<" ";
    // cout<<endl;

    cout << ans[num] << endl;
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