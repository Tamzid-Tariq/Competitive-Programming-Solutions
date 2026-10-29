/*
Problem: Minimum Euclidean Distance
Link: https://cses.fi/problemset/task/2194/
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
const long double pi = acos(-1.0);
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
	long double dist() const { return sqrt((long double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	long double angle() const { return atan2(y, x); }
	P unit() const { return *this / dist(); } // makes dist()=1
	P perp() const { return P(-y, x); }		  // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(long double a) const
	{
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
};

template <class P>
long double lineDist(const P &a, const P &b, const P &p)
{
	return (long double)(b - a).cross(p - a) / (b - a).dist();
}

// Usage: bool left = sideOf(p1,p2,q)==1;
template <class P>
ll sideOf(const P &s, const P &e, const P &p)
{
	auto a = (e - s).cross(p - s);
	return (a > 0) - (a < 0);
}
template <class P>
ll sideOf(const P &s, const P &e, const P &p, long double eps)
{
	auto a = (e - s).cross(p - s);
	long double l = (e - s).dist() * eps;
	return (a > l) - (a < -l);
}

// Usage: Point<long double> intersection, dummy;
// if (segmentIntersection(s1,e1,s2,e2,intersection,dummy)==1)
// cout << "segments intersect at " << intersection << endl;

template <class P>
int segmentIntersection(const P &s1, const P &e1,
						const P &s2, const P &e2, P &r1, P &r2)
{
	if (e1 == s1)
	{
		if (e2 == s2)
		{
			if (e1 == e2)
			{
				r1 = e1;
				return 1;
			} // all equal
			else
				return 0; // different point segments
		}
		else
			return segmentIntersection(s2, e2, s1, e1, r1, r2); // swap
	}
	// segment directions and separation
	P v1 = e1 - s1, v2 = e2 - s2, d = s2 - s1;
	auto a = v1.cross(v2), a1 = v1.cross(d), a2 = v2.cross(d);
	if (a == 0)
	{ // if parallel
		auto b1 = s1.dot(v1), c1 = e1.dot(v1),
			 b2 = s2.dot(v1), c2 = e2.dot(v1);
		if (a1 || a2 || max(b1, min(b2, c2)) > min(c1, max(b2, c2)))
			return 0;
		r1 = min(b2, c2) < b1 ? s1 : (b2 < c2 ? s2 : e2);
		r2 = max(b2, c2) > c1 ? e1 : (b2 > c2 ? s2 : e2);
		return 2 - (r1 == r2);
	}
	if (a < 0)
	{
		a = -a;
		a1 = -a1;
		a2 = -a2;
	}
	if (0 < a1 || a < -a1 || 0 < a2 || a < -a2)
		return 0;
	r1 = s1 - v1 * a2 / a;
	return 1;
}

// Clockwise enumeration gives negative area. Watch out for overflow if using int as T!

template <class T>
T polygonArea2(vector<Point<T>> &v)
{
	T a = v.back().cross(v[0]);
	for (ll i = 0; i < v.size() - 1; i++)
		a += v[i].cross(v[i + 1]);
	return a;
}

// Usage: typedef Point<int> pi; vector<pi> v; v.push_back(pi(4,4));
// v.push_back(pi(1,2)); v.push_back(pi(2,1));
// bool in = insidePolygon(v.begin(),v.end(), pi(3,4), false);

template <class P>
bool onSegment(const P &s, const P &e, const P &p)
{
	P ds = p - s, de = p - e;
	return ds.cross(de) == 0 && ds.dot(de) <= 0;
}

template <class It, class P>
bool insidePolygon(It begin, It end, const P &p,
				   bool strict = true)
{
	int n = 0; // number of isects with line from p to (inf,p.y)
	for (It i = begin, j = end - 1; i != end; j = i++)
	{
		// if p is on edge of polygon
		if (onSegment(*i, *j, p))
			return !strict;
		// or: if (segDist(*i, *j, p) <= epsilon) return !strict;
		// increment n if segment intersects line from p
		n += (max(i->y, j->y) > p.y && min(i->y, j->y) <= p.y &&
			  ((*j - *i).cross(p - *i) > 0) == (i->y <= p.y));
	}
	return n & 1; // inside if odd number of intersections
}

// Usage: vector<P> ps, hull;
// for(auto& i : convexHull(ps)) hull.push_back(ps[i]);
typedef Point<ll> P;
pair<vector<int>, vector<int>> ulHull(const vector<P> &S)
{
	vector<int> Q(S.size()), U, L;
	iota(Q.begin(), Q.end(), 0);
	sort(Q.begin(), Q.end(), [&S](int a, int b)
		 { return S[a] < S[b]; });
	for (auto &it : Q)
	{
#define ADDP(C, cmp)                                      \
	while (C.size() > 1 && S[C[C.size() - 2]].cross(      \
							   S[it], S[C.back()]) cmp 0) \
		C.pop_back();                                     \
	C.push_back(it);
		ADDP(U, <); // <= if Points on the edge of the hull between two other points are not considered part of the hull.
		ADDP(L, >); // >= if Points on the edge of the hull between two other points are not considered part of the hull.
	}
	return {U, L};
}

vector<int> convexHull(const vector<P> &S)
{
	vector<int> u, l;
	tie(u, l) = ulHull(S);
	if (S.size() <= 1)
		return u;
	if (S[u[0]] == S[u[1]])
		return {0};
	l.insert(l.end(), u.rbegin() + 1, u.rend() - 1);
	return l;
}

template <class It>
bool it_less(const It &i, const It &j) { return *i < *j; }
template <class It>
bool y_it_less(const It &i, const It &j) { return i->y < j->y; }

template <class It, class IIt> /* IIt = vector<It>::iterator */
double cp_sub(IIt ya, IIt yaend, IIt xa, It &i1, It &i2)
{
	typedef typename iterator_traits<It>::value_type P;
	int n = yaend - ya, split = n / 2;
	if (n <= 3)
	{ // base case
		double a = (*xa[1] - *xa[0]).dist(), b = 1e50, c = 1e50;
		if (n == 3)
			b = (*xa[2] - *xa[0]).dist(), c = (*xa[2] - *xa[1]).dist();
		if (a <= b)
		{
			i1 = xa[1];
			if (a <= c)
				return i2 = xa[0], a;
			else
				return i2 = xa[2], c;
		}
		else
		{
			i1 = xa[2];
			if (b <= c)
				return i2 = xa[0], b;
			else
				return i2 = xa[1], c;
		}
	}
	vector<It> ly, ry, stripy;
	P splitp = *xa[split];
	double splitx = splitp.x;
	for (IIt i = ya; i != yaend; ++i)
	{ // Divide
		if (*i != xa[split] && (**i - splitp).dist2() < 1e-12)
			return i1 = *i, i2 = xa[split], 0; // nasty special case!
		if (**i < splitp)
			ly.push_back(*i);
		else
			ry.push_back(*i);
	} // assert((signed)lefty.size() == split)
	It j1, j2; // Conquer
	double a = cp_sub(ly.begin(), ly.end(), xa, i1, i2);
	double b = cp_sub(ry.begin(), ry.end(), xa + split, j1, j2);
	if (b < a)
		a = b, i1 = j1, i2 = j2;
	double a2 = a * a;
	for (IIt i = ya; i != yaend; ++i)
	{ // Create strip (y-sorted)
		double x = (*i)->x;
		if (x >= splitx - a && x <= splitx + a)
			stripy.push_back(*i);
	}
	for (IIt i = stripy.begin(); i != stripy.end(); ++i)
	{
		const P &p1 = **i;
		for (IIt j = i + 1; j != stripy.end(); ++j)
		{
			const P &p2 = **j;
			if (p2.y - p1.y > a)
				break;
			double d2 = (p2 - p1).dist2();
			if (d2 < a2)
				i1 = *i, i2 = *j, a2 = d2;
		}
	}
	return sqrt(a2);
}

template <class It> // It is random access iterators of point<T>
double closestpair(It begin, It end, It &i1, It &i2)
{
	vector<It> xa, ya;
	assert(end - begin >= 2);
	for (It i = begin; i != end; ++i)
		xa.push_back(i), ya.push_back(i);
	sort(xa.begin(), xa.end(), it_less<It>);
	sort(ya.begin(), ya.end(), y_it_less<It>);
	return cp_sub(ya.begin(), ya.end(), xa.begin(), i1, i2);
}

void solve()
{
	ll num;
	cin >> num;

	vector<Point<ll>> vec(num);

	for (auto &[it, lit] : vec)
		cin >> it >> lit;

	vector<Point<ll>>::iterator p1, p2;
	closestpair(vec.begin(), vec.end(), p1, p2);

	ll disx = abs(p1->x - p2->x), disy = abs(p1->y - p2->y);
	cout << disx * disx + disy * disy << endl;
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