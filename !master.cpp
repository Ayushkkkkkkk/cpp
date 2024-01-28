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



namespace var_mint_ns {
struct VarModular {
    using value_type = int;
  private:
    static value_type P;
  public:
    value_type value;

    VarModular(long long k = 0) : value(norm(k)) {}

    friend VarModular& operator += (      VarModular& n, const VarModular& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend VarModular  operator +  (const VarModular& n, const VarModular& m) { VarModular r = n; return r += m; }

    friend VarModular& operator -= (      VarModular& n, const VarModular& m) { n.value -= m.value; if (n.value < 0)    n.value += P; return n; }
    friend VarModular  operator -  (const VarModular& n, const VarModular& m) { VarModular r = n; return r -= m; }
    friend VarModular  operator -  (const VarModular& n)                      { return VarModular(-n.value); }

    friend VarModular& operator *= (      VarModular& n, const VarModular& m) { n.value = reduce(n.value * 1ll * m.value); return n; }
    friend VarModular  operator *  (const VarModular& n, const VarModular& m) { VarModular r = n; return r *= m; }

    friend VarModular& operator /= (      VarModular& n, const VarModular& m) { return n *= m.inv(); }
    friend VarModular  operator /  (const VarModular& n, const VarModular& m) { VarModular r = n; return r /= m; }

    VarModular& operator ++ (   ) { return *this += 1; }
    VarModular& operator -- (   ) { return *this -= 1; }
    VarModular  operator ++ (int) { VarModular r = *this; *this += 1; return r; }
    VarModular  operator -- (int) { VarModular r = *this; *this -= 1; return r; }

    friend bool operator == (const VarModular& n, const VarModular& m) { return n.value == m.value; }
    friend bool operator != (const VarModular& n, const VarModular& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    static value_type           mod()      { return     P; }

    value_type norm(long long k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    VarModular inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return VarModular(x);
    }

  private:
    static uint64_t m;
  public:
    static void set_mod(value_type mod) {
        m = (__uint128_t(1) << 64) / mod;
        P = mod;
    }

    static value_type reduce(uint64_t a) {
        uint64_t q = ((__uint128_t(m) * a) >> 64);
        a -= q * P;
        if (a >= P)
            a -= P;
        return a;
    }
};
uint64_t VarModular::m = 0;
VarModular pow(VarModular m, long long p) {
    VarModular r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}
VarModular::value_type VarModular::P;
// use "VarModular::set_mod([your value])" later

ostream& operator << (ostream& o, const VarModular& m) { return o << m.value; }
istream& operator >> (istream& i,       VarModular& m) { long long k; i >> k; m.value = m.norm(k); return i; }
string   to_string(const VarModular& m) { return to_string(m.value); }

using Mint = VarModular;
// using Mint = long double;

vector<Mint> f, fi;
void init_C(int n) {
    f.assign(n, 1); fi.assign(n, 1);
    for (int i = 2; i < n; ++i) f[i] = f[i - 1] * i;
    fi.back() = Mint(1) / f.back();
    for (int i = n - 2; i >= 0; --i) fi[i] = fi[i + 1] * (i + 1);
}
Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    else return f[n] * fi[k] * fi[n - k];
}
}
using namespace var_mint_ns;


template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

vector<vector<int>> dominator_tree(vector<vector<int>> g, int root) {
    int n = g.size();
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    swap(p[root], p[0]);
    swap(g[0], g[root]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            g[i][j] = p[g[i][j]];
        }
    }
    vector<vector<int>> tree(n);
    vector<vector<int>> bucket(n);
    vector<int> sdom(n), dom(n), par(n), label(n), dsu(n);
    vector<vector<int>> gi(n);
    vector<int> arr(n, -1), rev(n);
    int tm = 0;

    function<int(int, int)> ask = [&](int u, int x) {
        if (u == dsu[u]) return x ? -1 : u;
        int v = ask(dsu[u], x + 1);
        if (v < 0) return u;
        if (sdom[label[dsu[u]]] < sdom[label[u]])
            label[u] = label[dsu[u]];
        dsu[u] = v;
        return x ? v : label[u];
    };
    auto un = [&](int u, int v) {
        dsu[v] = u;
    };

    function<void(int)> dfs = [&](int v) {
        arr[v] = tm;
        rev[tm] = v;
        label[tm] = sdom[tm] = dsu[tm] = tm;
        ++tm;
        for (int k : g[v]) {
            if (arr[k] == -1) {
                dfs(k);
                par[arr[k]] = arr[v];
            }
            gi[arr[k]].pb(arr[v]);
        }
    };
    dfs(0);
    assert(tm == n);  // connected

    for (int i = n - 1; i >= 0; --i) {
        for (int j : gi[i]) {
            sdom[i] = min(sdom[i], sdom[ask(j, 0)]);
        }
        if (i != 0) bucket[sdom[i]].pb(i);
        for (int w : bucket[i]) {
            int v = ask(w, 0);
            if (sdom[v] == sdom[w]) dom[w] = sdom[w];
            else dom[w] = v;
        }
        if (i != 0) un(par[i], i);
    }
    for (int i = 1; i < n; ++i) {
        if (dom[i] != sdom[i])
            dom[i] = dom[dom[i]];
        tree[rev[dom[i]]].pb(rev[i]);
        tree[rev[i]].pb(rev[dom[i]]);
    }

    swap(tree[root], tree[0]);
    for (int i = 0; i < tree.size(); ++i) {
        for (int j = 0; j < tree[i].size(); ++j) {
            tree[i][j] = p[tree[i][j]];
        }
    }

    return tree;
}





void test() {
	int n ; cin >> n;
	vector<int> a(n) , temp(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	temp = a;
	int LOG = log2(n) + 1;
	vector<vector<int>> mat;
	mat.push_back(a);
	debug(LOG);
	map<int , int> mpp;
	int max_size = 0;
	while (LOG--) {
		for (int i = 0 ; i < n ; i++) {
			mpp[a[i]]++;
		}
		for (int i = 0 ; i < n ; i++) {
			a[i] = mpp[a[i]];
		}
		max_size++;
		mat.push_back(a);
		mpp.clear();
	}
	debug(mat);
	int q ; cin >> q;
	while (q--) {
		int x , k ; cin >> x >> k;
		if(k > max_size){
			k = max_size;
		}
		cout << mat[k][x - 1] << nline;
	}
}


int32_t main() {
	lnx();
	int t;
	cin >> t;
	W(t) {
		test();
	}
}
