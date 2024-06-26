#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//using namespace chrono;



//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define fastio() 		ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define LL 				long long
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

#define F_OR(i, a, b, s) 			for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) 					F_OR(i, 0, e, 1)
#define F_OR2(i, e) 				F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) 				F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) 			F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) 	e
#define F_ORC(...) 					GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) 					F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) 					for (auto& x: a)


typedef long long 			ll;
typedef unsigned long long 	ull;
typedef long double 		lld;


void _print(ll t) 		{cerr << t;}
void _print(int t) 		{cerr << t;}
void _print(string t) 	{cerr << t;}
void _print(char t) 	{cerr << t;}
void _print(lld t) 		{cerr << t;}
void _print(double t) 	{cerr << t;}
void _print(ull t) 		{cerr << t;}


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

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


template<class T> bool umin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}



string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b ? "true" : "false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
	res += char('0' + v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
	res += char('0' + b[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f = 1;
	string res;
	EACH(x, v) {
		if (!f)
			res += ' ';
		f = 0;
		res += to_string(x);
	}
	return res;
}


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


void sovle2() {

}


void solve() {
	int n , q; cin >> n >> q;
	vector<int> a(n);
	vector<int> pref(n) , suff(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	pref[0] = a[0];
	for (int i = 1 ; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	suff[n - 1] = a[n - 1];
	for (int i = n - 2 ; i >= 0 ; i--) {
		suff[i] = suff[i + 1] + a[i];
	}
	while (q--) {
		int l , r , k ; cin >> l >> r >> k;
		int pref_sum = 0;
		int suff_sum = 0;
		l--;
		r--;
		if (l > 0) {
			pref_sum = pref[l - 1];
		}
		if (r < n) {
			suff_sum = suff[r + 1];
		}
		int ans = 0;
		if(l == 0 && r == n - 1){
			ans = pref[n - 1];
		}
		else
			ans = pref_sum + suff_sum + k * (r - l + 1);
		debug(ans);
		if (ans % 2 == 1) {
			cout << "YES" << nline;
		}
		else {
			cout << "NO" << nline;
		}
	}

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	int tt ; cin >> tt ; while (tt--) {solve();}
}













