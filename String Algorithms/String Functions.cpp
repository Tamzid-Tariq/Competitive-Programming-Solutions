/*
Problem: String Functions
Link: https://cses.fi/problemset/task/2107/
Author: Tamzid Tariq
Date: 2026-02-10
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

#define MAXLEN 1000006

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b)
{
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init()
{
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++)
    {
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash
{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T> &ar)
    {
        if (!base_pow[0])
            init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++)
        {
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod)
                pref[i] -= mod;
        }

        // for (int i = n; i >= 1; i--)
        // {
        //     suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
        //     if (suff[i] >= mod)
        //         suff[i] -= mod;
        // }
    }

    PolyHash(string &str)
        : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash(int l, int r)
    {
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r)
    {
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};

vector<ll>preftable;

void PrefixTable(string &need)
{
    ll siz = need.size();

    preftable[0] = -1;

    ll start = -1;

    for (ll i = 0; i < siz; i++)
    {
        while (start >= 0 && need[i] != need[start])
            start = preftable[start];
        start++;
        preftable[i+1] = start;
        cout<<preftable[i+1]<<" ";
    }
    cout<<endl;
}

void solve()
{
    string s;
    cin>>s;

    ll num=s.size();
    preftable.resize(num+2);

    PolyHash ph(s);

    cout<<0<<" ";

    for(int i=1;i<num;i++)
    {
        ll lo=0,hi=num-i,got=0;

        while(lo<=hi)
        {
            ll mid=(lo +hi)>>1LL;

            if(ph.get_hash(0,mid-1) == ph.get_hash(i,i+mid-1))
            {
                got=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        cout<<got<<" ";
    }
    cout<<endl;

    PrefixTable(s);
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