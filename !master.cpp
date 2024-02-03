#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

const string RandString = "20257I0MPJMLKOQA";

#define fastio()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr)
#define LL long long
#define LLD long double
#define i64 int64_t
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define lower(s1) transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
#define upper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define getunique(v)                      \
	{                                     \
		sort(all(v));                     \
		v.erase(unique(all(v)), v.end()); \
	}
#define vt vector
#define decimal cout << fixed << setprecision(15);
#define W(t) while (t--)

void lnx()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb)
{
	while (lb < rb)
	{
		ll mb = (lb + rb) / 2;
		f(mb) ? rb = mb : lb = mb + 1;
	}
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb)
{
	while (lb < rb)
	{
		ll mb = (lb + rb + 1) / 2;
		f(mb) ? lb = mb : rb = mb - 1;
	}
	return lb;
}

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.ff);
	cerr << ",";
	_print(p.ss);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

template <typename T>
vector<T> &operator--(vector<T> &v)
{
	for (auto &i : v)
		--i;
	return v;
}
template <typename T>
vector<T> &operator++(vector<T> &v)
{
	for (auto &i : v)
		++i;
	return v;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
	for (auto &i : v)
		is >> i;
	return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
	for (auto &i : v)
		os << i << ' ';
	return os;
}
template <typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p)
{
	--p.first;
	--p.second;
	return p;
}
template <typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p)
{
	++p.first;
	++p.second;
	return p;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p)
{
	is >> p.first >> p.second;
	return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p)
{
	os << p.first << ' ' << p.second;
	return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }
template <typename T, typename U>
void umin(T &a, U b)
{
	if (a > b)
		a = b;
}
template <typename T, typename U>
void umax(T &a, U b)
{
	if (a < b)
		a = b;
}

#ifndef ONLINE_JUDGE
#define debug(x)       \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

#define int long long

#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define miniA(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxiA(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)


const int MAX_N = 100005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return min(m[L][k], m[R - (1 << k) + 1][k]);
}

void SPARSE() {
	int n;
	cin >> n;
	bin_log[1] = 0;
	for (int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i / 2] + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	//  O(N*log(N))
	for (int k = 1; k < LOG; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << query(L, R) << "\n";
	}
}

void masking()
{
	int n;
	cin >> n;
	vector<int> masks(n, 0);
	for (int i = 0; i < n; i++)
	{
		int num_workers;
		cin >> num_workers;
		int mask = 0;
		for (int j = 0; j < num_workers; ++j)
		{
			int day;
			cin >> day;
			mask = (mask | (1 << day));
		}
		masks[i] = mask;
	}
	int max_days = 0;
	int person1 = -1;
	int person2 = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int interSection = (masks[i] & masks[j]);
			int common_days = __builtin_popcount(interSection);
			if (common_days > max_days)
			{
				max_days = common_days;
				person1 = i;
				person2 = j;
			}
			max_days = max(max_days, common_days);
		}
	}
}
vector<vector<int>> subsets(vector<int> &nums)
{
	int n = nums.size();
	int subsets_ct = (1 << n);
	vector<vector<int>> outer;
	for (int mask = 0; mask < subsets_ct; mask++)
	{
		vector<int> inner;
		for (int i = 0; i < n; ++i)
		{
			if (mask & (1 << i) != 0)
			{
				inner.emplace_back(nums[i]);
			}
		}
		outer.emplace_back(inner);
	}
	return outer;
}

void bitMaskinSubset()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
}

void XOR() {
	ll c;
	cin >> c;
	ll bit_ct = (ll)log2(c) + 1;
	ll a = 0 , b = 0;
	vector<ll> set_bits;
	for (ll i = 0; i < bit_ct; ++i) {
		if (c & (1 << i)) {
			set_bits.push_back(i);
		}
		else {
			a |= (1 << i);
			b |= (1 << i);
		}
	}
	ll ans = 0;
	ll sz = 1 << set_bits.size();
	for (ll mask = 0; mask < sz ; mask++) {
		ll a_copy = a , b_copy = b;
		for (ll j = 0; j < set_bits.size(); j++) {
			if (mask & (mask << j)) {
				a_copy |= (1 << set_bits[j]);
			}
			else {
				a_copy |= (1 << set_bits[j]);
			}
		}
		ans = max(ans , a_copy * 1LL * b_copy);
	}
	cout << ans << nline;
}


void test() {
	i64 a , b , k; cin >> a >> b >> k;
	i64 mx_pos = 0;;
	for (i64 i = 0 ; i < 64 ; i++) {
		if ((k >> 1) & 1)
			mx_pos = i;
	}

	for (i64 i = 63 ; i >= 0 ; i--) {
		i64 a_bit = ((a >> i) & 1);
		i64 b_bit = ((b >> i) & 1);

		if (a_bit != b_bit) {
			if (a_bit == 1) {

			}
			else {
				swap(a , b);
			}
			break;
		}
	}

	function<int(int , int , int)> find = [&](int a , int b , int k)->int{
		bool flag = false;
		i64 x = 0;
		for (i64 i = 63 ; i >= 0 ; i--) {
			i64 a_bit = ((a >> i) & 1);
			i64 b_bit = ((b >> i) & 1);
			
			if(a_bit == 1 && b_bit == 0){
				if(!flag){
					flag = true;
				}
				else{
					i64 nx = x + (1ll << i);
					if(nx <= k){
						x += (1ll << i);
					}
					else{
						x += 0;
					}
				}
			}
			else{
				
			}
		}
		
		a ^= x;
		b ^= x;
		return abs(a - b);
	};
	
	
	cout << find(a , b , k) << nline;
}


int32_t main() {
	lnx();
	int t;
	cin >> t;
	W(t)
	{
		test();
	}
}
