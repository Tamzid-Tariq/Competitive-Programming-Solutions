/*
Problem: Signal Processing
Link: https://cses.fi/problemset/task/2113/
Author: Tamzid Tariq
Date: 2026-09-01
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

const ll N = 3e5 + 9;
const double PI = acos(-1);

struct base
{
    double a, b;

    base(double a = 0, double b = 0) : a(a), b(b) {}

    const base operator+(const base &c) const
    {
        return base(a + c.a, b + c.b);
    }

    const base operator-(const base &c) const
    {
        return base(a - c.a, b - c.b);
    }

    const base operator*(const base &c) const
    {
        return base(
            a * c.a - b * c.b,
            a * c.b + b * c.a);
    }
};

void fft(vector<base> &p, bool inv = 0)
{
    ll n = p.size(), i = 0;

    // Bit-reversal permutation
    for (ll j = 1; j < n - 1; ++j)
    {
        for (ll k = n >> 1; k > (i ^= k); k >>= 1)
            ;

        if (j < i)
            swap(p[i], p[j]);
    }

    // Cooley-Tukey FFT
    for (ll l = 1, m; (m = l << 1) <= n; l <<= 1)
    {
        double ang = 2 * PI / m;

        base wn(
            cos(ang),
            (inv ? -1. : 1.) * sin(ang)),
            w;

        for (ll i = 0, j, k; i < n; i += m)
        {
            for (
                w = base(1, 0), j = i, k = i + l;
                j < k;
                ++j, w = w * wn)
            {
                base t = w * p[j + l];

                p[j + l] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }

    // Normalize inverse FFT
    if (inv)
    {
        for (ll i = 0; i < n; ++i)
            p[i].a /= n,
                p[i].b /= n;
    }
}

vector<long long> multiply(vector<ll> &a, vector<ll> &b)
{
    ll n = a.size(),
       m = b.size(),
       t = n + m - 1,
       sz = 1;

    // Size of FFT = power of two >= n + m - 1
    while (sz < t)
        sz <<= 1;

    vector<base> x(sz), y(sz), z(sz);

    for (ll i = 0; i < sz; ++i)
    {
        x[i] = i < (ll)a.size()
                   ? base(a[i], 0)
                   : base(0, 0);

        y[i] = i < (ll)b.size()
                   ? base(b[i], 0)
                   : base(0, 0);
    }

    fft(x);
    fft(y);

    for (ll i = 0; i < sz; ++i)
        z[i] = x[i] * y[i];

    fft(z, 1);

    vector<long long> ret(sz);

    for (ll i = 0; i < sz; ++i)
        ret[i] = (long long)round(z[i].a);

    // size of the resultant polynomial is two's power
    return ret;
}

void solve()
{
    ll num, num2;
    cin >> num >> num2;

    vector<ll> vec(num);
    for (auto &it : vec)
    {
        cin >> it;
    }

    vector<ll> vecb(num2);
    for (auto &it : vecb)
        cin >> it;

    reverse(vecb.begin(), vecb.end());

    vector<ll> ans = multiply(vec, vecb);

    for (ll i = 0; i < num + num2 - 1; i++)
        cout << ans[i] << " ";
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