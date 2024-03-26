#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <chrono>


using namespace std;
using namespace __gnu_pbds;
//using namespace chrono;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define read(x) int x; cin>>x
#define set_bits __builtin_popcountll
#define lower(s) transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
#define upper(s) transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define i64 int64_t


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


#define int long long

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

const lld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll INF = 1e18;

int predicate(int n , int m  , int x){
	int temp = min(n , m);
	int ans = min(temp , n + m + x);
	return ans;
}

void solver() {
	int n , m , x ;
	cin>>n>>m>>x;
	if(n == 0 || m == 0){
		cout<<0<<nline;
		return;
	}
	if(n + m + x < 3){
		cout<<0<<nline;
		return;
	}
	bool over = false;
	int low = 0  , high = m + n + x;
	int mid = 0 , res = 0;
	while(high - low > 1){
		mid = (low + high) / 2;
		over = (predicate(n , m , x) <= mid);
		if(over){
			high = mid - 1;
			res = mid;
		}
		else{
			low = mid + 1;
		}
	}
	cout<<low + 1<<nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	ll tt;
	cin >> tt;
	while (tt--) {
		solver();
	}
}













