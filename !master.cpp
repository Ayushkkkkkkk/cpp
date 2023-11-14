#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

const string RandString = "20257I0MPJMLKOQA";



#define fastio() 		ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define LL 				long long
#define LLD				long double
#define nline 			"\n"
#define pb 				push_back
#define ppb 			pop_back
#define mp 				make_pair
#define ff 				first
#define ss 				second
#define set_bits 		__builtin_popcountll
#define sz(x) 			((int)(x).size())
#define all(x) 			(x).begin(), (x).end()
#define set_bits 		__builtin_popcountll
#define lower(s1) 		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
#define upper(s1) 		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define getunique(v) 	{sort(all(v)); v.erase(unique(all(v)), v.end());}
#define vt vector
#define decimal 		cout << fixed << setprecision(15) ;
#define W(t)        	while(t--)


void lnx() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
}

typedef long long 			ll;
typedef unsigned long long 	ull;
typedef long double 		lld;


ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb) / 2;
		f(mb) ? rb = mb : lb = mb + 1;
	}
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb + 1) / 2;
		f(mb) ? lb = mb : rb = mb - 1;
	}
	return lb;
}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void _print(ll t) 		{cerr << t;}
void _print(int t) 		{cerr << t;}
void _print(string t) 	{cerr << t;}
void _print(char t) 	{cerr << t;}
void _print(lld t) 		{cerr << t;}
void _print(double t) 	{cerr << t;}
void _print(ull t) 		{cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T>  		void _print(vector <T> v);
template <class T>  		void _print(set <T> v);
template <class T>  		void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T>  		void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) 			{cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); 		cerr << "}";}
template <class T> 			void _print(vector <T> v) 			{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(set <T> v) 				{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(multiset <T> v) 		{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}
template <class T, class V> void _print(map <T, V> v) 			{cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} 	cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} 	cerr << "]";}
template <class T> 			void _print(unordered_set <T> v) 	{cerr << "[ "; for (T i : v) 	{_print(i); cerr << " ";} 	cerr << "]";}


template<typename T>             vector<T>& operator--            (vector<T> &v) {for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v) {for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v) {for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v) {for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T, U>& operator--           (pair<T, U> &p) {--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T, U>& operator++           (pair<T, U> &p) {++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p) {is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {return mp(a.first - b.first, a.second - b.second);}
template<typename T, typename U> pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {return mp(a.first + b.first, a.second + b.second);}
template<typename T, typename U> void umin(T& a, U b) {if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b) {if (a < b) a = b;}



#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long


#define sum(a)     	( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    	(*min_element((a).begin(), (a).end()))
#define maxe(a)    	(*max_element((a).begin(), (a).end()))
#define miniA(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxiA(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) 	( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) 	( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)


#define f first
#define s second
using namespace std;
#define int long long
const int maxn = 2e5 + 69;
const int k = 19;
const int bits = 30;
vector<int> g[maxn];
int n, q, a[maxn], up[maxn][k], tin[maxn], tout[maxn], timer, d[maxn];
int r[maxn][k];
int bst[maxn][bits];
void dfs(int v, int p, vector<int> b) {
	tin[v] = ++timer;
	up[v][0] = p;
	r[v][0] = a[p];
	d[v] = d[p] + 1;
	for (int i = 0; i < bits; i++) {
		bst[v][i] = b[i];
		if (a[v] & (1 << i))
			b[i] = v;
	}
	for (int i = 1; i < k; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		r[v][i] = r[v][i - 1] | r[up[v][i - 1]][i - 1];
	}
	for (auto u : g[v]) {
		if (u != p)
			dfs(u, v, b);
	}
	tout[v] = timer;
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_anc(u, v))
		return u;
	else if (is_anc(v, u))
		return v;
	for (int i = k - 1; i >= 0; i--) {
		if (!is_anc(up[u][i], v) && up[u][i] > 0)
			u = up[u][i];
	}
	return up[u][0];
}

int OR(int u, int dis) {
	int res = a[u];
	for (int j = 0; j < bits; j++) {
		if (dis & (1 << j)) {
			res |= r[u][j];
			u = up[u][j];
		}
	}
	return res;
}

int Qry(int u, int v) {
	int lc = lca(u, v);
	return OR(u, d[u] - d[lc]) | OR(v, d[v] - d[lc]);
}


void test() {
	cin >> n;
	timer = 0;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> temp(30, -1);
	dfs(1, 0, temp);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int LCA = lca(x, y);
		vector<int> t;
		t.push_back(x);
		t.push_back(y);
		for (int i = 0; i < bits; i++) {
			if (bst[x][i] != -1 && is_anc(LCA, bst[x][i]))
				t.push_back(bst[x][i]);
			if (bst[y][i] != -1 && is_anc(LCA, bst[y][i]))
				t.push_back(bst[y][i]);
		}
		int ans =  __builtin_popcount(a[x]) + __builtin_popcount(a[y]);
		for (auto p : t) {
			int x1 = a[x], x2 = a[y];
			x1 |= Qry(x, p);
			x2 |= Qry(y, p);
			ans = max(ans, 1ll * __builtin_popcount(x1) + __builtin_popcount(x2));
		}
		cout << ans << " ";
	}
	cout << "\n";
}



int32_t main() {
	lnx();
	int t;
	cin >> t;
	W(t) {
		test();
	}
}


