#include <bits/stdc++.h>
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


void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}


void test() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    string s ; cin >> s;
    int xor1 = 0, xor0 = 0;
    for (int i = 0 ; i < n ; i++){
        if(s[i] == '0'){
            xor0 ^= a[i];
        }
        else{
            xor1 ^= a[i];
        }
    }

    vector<int> prefXor(n);
    prefXor[0] = a[0];
    for (int i = 1 ; i < n ; i++){
        prefXor[i] = prefXor[i - 1] ^ a[i];
    }
    //debug(prefXor);


    int q ; cin >> q;
    for (int i = 0 ; i < q ; i++){
        int dx;
        cin >> dx;
        if(dx == 1){
            int l , r ; cin >> l >> r;
            l-- , r--;
            if(l == 0){
                xor1 ^= prefXor[r];
                xor0 ^= prefXor[r];
            }
            else{
                xor1 ^= prefXor[r] ^ prefXor[l - 1];
                xor0 ^= prefXor[r] ^ prefXor[l - 1];
            }
        }
        else{
            int tx ; cin >> tx;
            if(tx == 0){
                cout << xor0 << " ";
            }
            else{
                cout << xor1 << " ";
            }
        }
    }
    cout << nline;
}




int32_t main() {
  fastio();
  int t;
  cin >> t;
  W(t) {
      test(); 
  }
}
