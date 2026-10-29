/*
Problem: Maximum Xor Subarray
Link: https://cses.fi/problemset/task/1655/
Author: Tamzid Tariq
Date: 2026-03-09
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

const int K = 2;

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
        int c = ch - '0';
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

void solve()
{
    ll num;
    cin >> num;

    vector<ll> vec(num);
    for (auto &it : vec)
        cin >> it;

    vector<ll> pref(num + 1);

    ll ans = *max_element(vec.begin(), vec.end());
    for (ll i = 1; i <= num; i++)
    {
        pref[i] = (pref[i - 1] ^ vec[i - 1]);

        string now;

        for (ll j = 29; j >= 0; j--)
        {
            if (pref[i] & (1LL << j))
                now += '1';
            else
                now += '0';
        }

        ll got = 0;
        add_string(now);

        if (i > 1)
        {
            ll start = 0;

            for (ll j = 29; j >= 0; j--)
            {
                int c = (now[29 - j] - '0') ^ 1;
                if (trie[start].next[c] != -1)
                {
                    got |= (1LL << j);
                    start = trie[start].next[c];
                }
                else if (trie[start].next[c ^ 1] != -1)
                    start = trie[start].next[c ^ 1];

                else
                    break;
            }
        }
        // cout<<now<<" "<<got<<endl;

        ans = max({ans, got, pref[i]});
    }

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