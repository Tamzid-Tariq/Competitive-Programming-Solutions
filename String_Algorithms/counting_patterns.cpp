/*
Problem: Counting Patterns
Link: https://cses.fi/problemset/task/2103/
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

struct SuffixArray
{
    int num;
    vector<int> clas, sorted, temp, lcp;
    string s;

    void build(string &st)
    {
        s = st;
        s += '$';
        num = s.size();

        clas.resize(num), sorted.resize(num), lcp.resize(num);

        iota(sorted.begin(), sorted.end(), 0LL);

        sort(sorted.begin(), sorted.end(), [&](ll ind1, ll ind2)
             { return s[ind1] < s[ind2]; });

        clas[sorted[0]] = 0;

        for (int i = 1; i < num; i++)
        {
            clas[sorted[i]] = clas[sorted[i - 1]] + (s[sorted[i]] != s[sorted[i - 1]]);
        }

        int k = 0;

        while ((1LL << k) < num)
        {
            sort(sorted.begin(), sorted.end(), [&](ll ind, ll ind2)
                 { return (make_pair(clas[ind], clas[(ind + (1LL << k)) % num]) < make_pair(clas[ind2], clas[(ind2 + (1LL << k)) % num])); });

            temp = clas;
            temp[sorted[0]] = 0;
            for (int i = 1; i < num; i++)
            {
                temp[sorted[i]] = temp[sorted[i - 1]] + (make_pair(clas[sorted[i]], clas[(sorted[i] + (1LL << k)) % num]) != make_pair(clas[sorted[i - 1]], clas[(sorted[i - 1] + (1LL << k)) % num]));
            }

            clas = temp;

            k++;
        }

        k = 0;

        for (int i = 0; i < num - 1; i++)
        {
            int pi = clas[i];
            int j = sorted[pi - 1];

            while (s[i + k] == s[j + k])
                k++;

            lcp[pi] = k;
            k = max(0, k - 1);
        }
    }

    void lcs(string &one, string &two)
    {
        s = one;
        s += '$';
        int num1 = s.size();
        s += two;
        s += '#';
        num = s.size();

        clas.resize(num), sorted.resize(num), lcp.resize(num);

        iota(sorted.begin(), sorted.end(), 0LL);

        sort(sorted.begin(), sorted.end(), [&](ll ind1, ll ind2)
             { return s[ind1] < s[ind2]; });

        clas[sorted[0]] = 0;

        for (int i = 1; i < num; i++)
        {
            clas[sorted[i]] = clas[sorted[i - 1]] + (s[sorted[i]] != s[sorted[i - 1]]);
        }

        int k = 0;

        while ((1LL << k) < num)
        {
            sort(sorted.begin(), sorted.end(), [&](ll ind, ll ind2)
                 { return (make_pair(clas[ind], clas[(ind + (1LL << k)) % num]) < make_pair(clas[ind2], clas[(ind2 + (1LL << k)) % num])); });

            temp = clas;
            temp[sorted[0]] = 0;
            for (int i = 1; i < num; i++)
            {
                temp[sorted[i]] = temp[sorted[i - 1]] + (make_pair(clas[sorted[i]], clas[(sorted[i] + (1LL << k)) % num]) != make_pair(clas[sorted[i - 1]], clas[(sorted[i - 1] + (1LL << k)) % num]));
            }

            clas = temp;

            k++;
        }

        k = 0;

        for (int i = 0; i < num - 1; i++)
        {
            int pi = clas[i];
            int j = sorted[pi - 1];

            while (s[i + k] == s[j + k])
                k++;

            lcp[pi] = k;
            k = max(0, k - 1);
        }

        ll start = 0, len = 0;
        for (int i = 1; i < num; i++)
        {
            if ((sorted[i] < num1) != (sorted[i - 1] < num1))
            {
                // cout<<lcp[i]<<" ";
                if (lcp[i] > len)
                    start = sorted[i - 1], len = lcp[i];
            }
        }

        cout << s.substr(start, len) << endl;
    }

    ll find(string &given)
    {
        int len = given.size();

        ll lo = 0, hi = num - 1, got = num;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (s.substr(sorted[mid], len) == given)
            {
                got = mid;
                hi = mid - 1;
            }
            else if (s.substr(sorted[mid], len) > given)
            {
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        lo = got, hi = num - 1;
        ll times = got - 1;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (s.substr(sorted[mid], len) == given)
            {
                times = mid;
                lo = mid + 1;
            }
            else if (s.substr(sorted[mid], len) > given)
            {
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return times - got + 1;
    }

    ll different_substring()
    {
        ll total = (ll)(num) * (num - 1) / 2LL;

        return (ll)total - accumulate(lcp.begin(), lcp.end(), 0LL);
    }
};

void solve()
{
    string s;
    cin >> s;

    ll siz = s.size();

    SuffixArray SA;
    SA.build(s);

    ll query;
    cin>>query;

    while(query--)
    {
        string given;
        cin>>given;

        cout<<(SA.find(given))<<endl;
    }
}

signed main()
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