/*
Problem: All Manhattan Distances
Link: https://cses.fi/problemset/task/3411/
Author: Tamzid Tariq
Date: 2026-03-16
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

// Typedefs for convenience
using int128 = __int128_t;
using uint128 = __uint128_t;

// 1. Overload for Output (std::cout << n)
std::ostream &operator<<(std::ostream &os, int128 n)
{
    if (n == 0)
        return os << "0";
    if (n < 0)
    {
        os << "-";
        n = -n;
    }
    std::string s;
    while (n > 0)
    {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

// 2. Overload for Input (std::cin >> n)
std::istream &operator>>(std::istream &is, int128 &n)
{
    std::string s;
    is >> s;
    n = 0;
    int i = 0;
    bool negative = false;
    if (s[0] == '-')
    {
        negative = true;
        i = 1;
    }
    for (; i < s.size(); i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    if (negative)
        n = -n;
    return is;
}

// Optional: Basic math helpers if needed
namespace Int128Utils
{
    int128 abs128(int128 n) { return n < 0 ? -n : n; }
}

void solve()
{
    ll num;
    cin >> num;

    vector<ll> x, y;
    vector<pair<ll, ll>> vec(num);
    for (auto &[it, lit] : vec)
    {
        cin >> it >> lit;
        x.push_back(it);
        y.push_back(lit);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int128 ans = 0LL, sum = 0LL;

    for (int i = 0; i < num; i++)
    {
        ans += x[i] * i - sum;
        sum += x[i];
    }

    sum = 0LL;
    for (int i = 0; i < num; i++)
    {
        ans += ((y[i] * i)) - sum;
        sum += (y[i]);
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