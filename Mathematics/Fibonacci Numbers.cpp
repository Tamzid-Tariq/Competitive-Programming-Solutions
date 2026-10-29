/*
Problem: Fibonacci Numbers
Link: https://cses.fi/problemset/task/1722/
Author: Tamzid Tariq
Date: 2026-05-27
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

struct Mat
{
    ll n, m;
    vector<vector<ll>> a;
    Mat() {}
    Mat(ll _n, ll _m)
    {
        n = _n;
        m = _m;
        a.assign(n, vector<ll>(m, 0));
    }
    Mat(vector<vector<ll>> v)
    {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }
    inline void make_unit()
    {
        assert(n == m);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                a[i][j] = (i == j);
    }
    inline Mat operator+(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans(n, m);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % modular;
        return ans;
    }
    inline Mat operator-(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans(n, m);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
                ans.a[i][j] = (a[i][j] - b.a[i][j] + modular) % modular;
        return ans;
    }
    inline Mat operator*(const Mat &b)
    {
        assert(m == b.n);
        Mat ans(n, b.m);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < b.m; j++)
                for (ll k = 0; k < m; k++)
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % modular) % modular;
        return ans;
    }
    inline Mat pow(long long k)
    {
        assert(n == m);
        Mat ans(n, n), t = a;

        ans.make_unit();
        while (k)
        {
            if (k & 1)
                ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
    inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
    inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
};

void solve()
{
    ll num;
    cin >> num;

    if (num <= 1)
    {
        cout << num << endl;
        return;
    }

    vector<vector<ll>> a = {{0, 1}, {1, 1}};
    vector<vector<ll>> b = {{1}, {0}};
    Mat A(a), B(b);

    // cout<<A.n<<" "<<A.m<<endl;

    A = A.pow(num);
    A = A * B;

    cout << A.a[1][0] << endl;
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