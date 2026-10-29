/*
Problem: Point Location Test
Link: https://cses.fi/problemset/task/2189/
Author: Tamzid Tariq
Date: 2026-03-15
Status: Accepted ✓
*/

#include <bits/stdc++.h>

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
using namespace std;
#define endl '\n';
const ll modular = 1e9 + 7;
const double pi = acos(-1.0);
const ll INF = 1e18;

template <class T>
struct Point
{
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); }       // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const
    {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
};

template <class P>
double lineDist(const P &a, const P &b, const P &p)
{
    return (double)(b - a).cross(p - a) / (b - a).dist();
}

// Usage: bool left = sideOf(p1,p2,q)==1;
template <class P>
ll sideOf(const P &s, const P &e, const P &p)
{
    auto a = (e - s).cross(p - s);
    return (a > 0) - (a < 0);
}
template <class P>
ll sideOf(const P &s, const P &e, const P &p, double eps)
{
    auto a = (e - s).cross(p - s);
    double l = (e - s).dist() * eps;
    return (a > l) - (a < -l);
}

void solve()
{
    Point<ll> a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    ll got = (sideOf(a, b, c));

    if (!got)
    {
        cout << "TOUCH\n";
    }
    else
    {
        cout << (got == 1 ? "LEFT\n" : "RIGHT\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    n = 1;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}