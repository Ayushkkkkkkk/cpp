#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;





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


#define F_OR(i, a, b, s) 			for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) 					F_OR(i, 0, e, 1)
#define F_OR2(i, e) 				F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) 				F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) 			F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) 	e
#define F_ORC(...) 					GET5(_VA_ARGS_, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) 					F_ORC(_VA_ARGS_)(_VA_ARGS_)
#define EACH(x, a) 					for (auto& x: a)

using pii = pair<int,int>;

template<typename T = int, T mod = 1000000007, typename U = long long>
struct umod{
    T val;
    umod(): val(0){}
    umod(U x){ x %= mod; if(x < 0) x += mod; val = x;}
    umod& operator += (umod oth){ val += oth.val; if(val >= mod) val -= mod; return *this; }
    umod& operator -= (umod oth){ val -= oth.val; if(val < 0) val += mod; return *this; }
    umod& operator *= (umod oth){ val = ((U)val) * oth.val % mod; return *this; }
    umod& operator /= (umod oth){ return *this *= oth.inverse(); }
    umod& operator ^= (U oth){ return *this = pwr(*this, oth); }
    umod operator + (umod oth) const { return umod(*this) += oth; }
    umod operator - (umod oth) const { return umod(*this) -= oth; }
    umod operator * (umod oth) const { return umod(*this) *= oth; }
    umod operator / (umod oth) const { return umod(*this) /= oth; }
    umod operator ^ (long long oth) const { return umod(*this) ^= oth; }
    bool operator < (umod oth) const { return val < oth.val; }
    bool operator > (umod oth) const { return val > oth.val; }
    bool operator <= (umod oth) const { return val <= oth.val; }
    bool operator >= (umod oth) const { return val >= oth.val; }
    bool operator == (umod oth) const { return val == oth.val; }
    bool operator != (umod oth) const { return val != oth.val; }
    umod pwr(umod a, U b) const { umod r = 1; for(; b; a *= a, b >>= 1) if(b&1) r *= a; return r; }
    umod inverse() const {
        U a = val, b = mod, u = 1, v = 0;
        while(b){
            U t = a/b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if(u < 0)
            u += mod;
        return u;
    }
};
 
using U = umod<int, 998244353>;

void test() {
	string s ; cin >> s;
	int n = s.size();
	
	vector<pii> z;
	for (int i = 0 , j = 0 ; i < n ; i = j){
		while(j < n && s[i] == s[j]) j++;
		z.emplace_back(i , j - 1);
	}
	int len = z.size();
	U last_sum = 1;
	int last_mx = 0;
	for (int i = 0 ; i < len ; i++){
		int l , r ; l = z[i].first , r = z[i].second;
		last_sum *= r - l + 1;
		last_mx++;
	}
	
	for (int i = n - last_mx ; i > 0 ; i--){
		last_sum *= i;
	}
	cout << n - last_mx << " " << last_sum.val << nline;
	
}



int32_t main() {
	lnx();
	int t; cin >> t;
	W(t) {
		test();
	}
}


