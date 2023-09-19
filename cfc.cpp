#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//using namespace chrono;


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
#define F_ORC(...) 					GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) 					F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) 					for (auto& x: a)


// in this question we are given some books and the minutes to read the book and we are given a size 2 binary string which can be 11 10 01 or any thing we have to find the minimum minutes to read book 1 and 2 which means
// the book in s[0] is the first book and book in the s[1] is the second book so in this case i have listed the minimum elem i can find from the s[1] and s[0] and if in some case i have book with s[0] = 1 and s[1] = 1 
// at last i will compare this with the two minumum i get and print the answer at the last 


void test() {
	int n ; cin >> n ;
	int mini_first = INT_MAX , mini_second = INT_MAX , mini_third = INT_MAX;
	bool have_first = false, have_second = false;
	int cost = -1;
	for (int i = 0 ; i < n ; i++){
		int x ; string s ; cin >> x >> s;
		if(s[0] == '1' && s[1] == '1'){
			have_first = true;
			have_second = true;
			cost = x;
			mini_third = min(mini_third , x);
		}
		else if(s[0] == '1'){
			mini_first = min(mini_first , x);
			have_first = true;
		}
		else if(s[1] == '1'){
			have_second = true;
			mini_second = min(mini_second , x);
		}
	}
	if(cost == -1 && have_first == false || have_second == false){
		cout << -1 << nline;
		return;
	}
	
	if(cost != -1){
		cout << min(mini_third , mini_second + mini_first) << nline;
	}
	else{
		cout << mini_second + mini_first << nline;
	}
}




int32_t main() {
	lnx();
	
	int t ; cin >> t;
	while (t--) {
		test();
	}
}