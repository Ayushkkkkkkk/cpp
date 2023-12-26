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



bool isPrime(int n)
{
	// Corner case
	if (n <= 1)
		return false;

	// Check from 2 to n-1
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;

	return true;
}



void test() {
	int n ; cin >> n ;
	string s ; cin >> s;
	int temp = -1;
	bool one = false;
	for (int i = 0 ; i < n ; i++) {
		bool ok = isPrime(s[i] - '0');
		if (!ok) {
			temp = s[i] - '0';
			one = true;
		}
	}

	if (one) {
		cout << 1 << nline;
		cout << temp << nline;
		return;
	}

	for (int i = 0 ; i < n ; i++) {
		int num = s[i] - '0';
		if (num == 1) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 12 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 14 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 15 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 16 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 18 << nline;
					return;
				}

			}
		}
		else if (num == 2) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '1') {
					cout << 2 << nline;
					cout << 21 << nline;
					return;
				}
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 22 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 24 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 25 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 26 << nline;
					return;
				}
				if (s[j] == '7') {
					cout << 2 << nline;
					cout << 27 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 28 << nline;
					return;
				}

			}
		}
		else if (num == 3) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 32 << nline;
					return;
				}
				if (s[j] == '3') {
					cout << 2 << nline;
					cout << 33 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 34 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 35 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 36 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 38 << nline;
					return;
				}
				if (s[j] == '9') {
					cout << 2 << nline;
					cout << 39 << nline;
					return;
				}

			}
		}
		else if (num == 4) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 42 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 44 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 45 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 46 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 48 << nline;
					return;
				}
				if (s[j] == '9') {
					cout << 2 << nline;
					cout << 49 << nline;
					return;
				}

			}
		}
		else if (num == 5) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '1') {
					cout << 2 << nline;
					cout << 51 << nline;
					return;
				}
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 52 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 54 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 55 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 56 << nline;
					return;
				}
				if (s[j] == '7') {
					cout << 2 << nline;
					cout << 57 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 58 << nline;
					return;
				}

			}
		}
		else if (num == 6) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 62 << nline;
					return;
				}
				if (s[j] == '3') {
					cout << 2 << nline;
					cout << 63 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 64 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 65 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 66 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 68 << nline;
					return;
				}
				if (s[j] == '9') {
					cout << 2 << nline;
					cout << 69 << nline;
					return;
				}

			}
		}
		else if (num == 7) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 72 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 74 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 75 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 76 << nline;
					return;
				}
				if (s[j] == '7') {
					cout << 2 << nline;
					cout << 77 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 78 << nline;
					return;
				}
				

			}
		}
		else if (num == 8) {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '1') {
					cout << 2 << nline;
					cout << 81 << nline;
					return;
				}
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 82 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 84 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 85 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 86 << nline;
					return;
				}
				if (s[j] == '7') {
					cout << 2 << nline;
					cout << 87 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 88 << nline;
					return;
				}

			}
		}
		else {
			for (int j = i + 1 ; j < n ; j++) {
				if (s[j] == '1') {
					cout << 2 << nline;
					cout << 91 << nline;
					return;
				}
				if (s[j] == '2') {
					cout << 2 << nline;
					cout << 92 << nline;
					return;
				}
				if (s[j] == '3') {
					cout << 2 << nline;
					cout << 92 << nline;
					return;
				}
				if (s[j] == '4') {
					cout << 2 << nline;
					cout << 94 << nline;
					return;
				}
				if (s[j] == '5') {
					cout << 2 << nline;
					cout << 95 << nline;
					return;
				}
				if (s[j] == '6') {
					cout << 2 << nline;
					cout << 96 << nline;
					return;
				}
				if (s[j] == '8') {
					cout << 2 << nline;
					cout << 98 << nline;
					return;
				}
				if (s[j] == '9') {
					cout << 2 << nline;
					cout << 99 << nline;
					return;
				}

			}
		}
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


