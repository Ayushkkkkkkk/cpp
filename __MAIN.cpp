#include <bits/stdc++.h>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

const string RandString = "20257I0MPJMLKOQA";

#define fastio()                                                               \
    ios_base::sync_with_stdio(false);                                            \
cin.tie(nullptr);                                                            \
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
#define getunique(v)                                                           \
{                                                                            \
    sort(all(v));                                                              \
    v.erase(unique(all(v)), v.end());                                          \
}
#define vt vector
#define decimal cout << fixed << setprecision(15);
#define W(t) while (t--)

#define DEBUG

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T> void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifdef DEBUG
#define debug(x...)                                                            \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
    _print(x);                                                                   \
    cerr << "\e[39m" << endl;
#else
#define debug(x...)
#endif

#define int long long

#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define miniA(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxiA(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

#define F_OR(i, a, b, s)                                                       \
    for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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

// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> vector<T> &operator--(vector<T> &v) {
    for (auto &i : v)
        --i;
    return v;
}
template <typename T> vector<T> &operator++(vector<T> &v) {
    for (auto &i : v)
        ++i;
    return v;
}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <typename T, typename U> pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}
template <typename T, typename U> pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
    return mp(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
    return mp(a.first + b.first, a.second + b.second);
}
template <typename T, typename U> void umin(T &a, U b) {
    if (a > b)
        a = b;
}
template <typename T, typename U> void umax(T &a, U b) {
    if (a < b)
        a = b;
}


const int N =200003;
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){ //Builds the prefix sums for each bit
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}


void test() {
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    Buildprefix(n);
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l-1]<k){
            cout << -1 << " ";
            continue;
        }
        int lo=l;
        int hi=n;
        int ans=l;
        while(lo<=hi){
            int s=(lo+hi)/2;
            int num=0;
            for(int j=0; j< bits; j++){
                if(pref[s][j]-pref[l-1][j]==s-l+1){
                    num+=(1<<j);
                }
            }
            if(num>=k){
                lo=s+1;
                ans=max(ans, s);
            }
            else hi=s-1;
        }
        cout << ans <<" ";
    }
    cout << nline;
}













int32_t main() {
    fastio();
    int t;
    cin >> t;
    W(t) { test(); }
}




