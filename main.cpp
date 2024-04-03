#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
// using namespace __gnu_pbds;
// using namespace chrono;

// const string RandString = "20257I0MPJMLKOQA";

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
// template <typename T = int>
// using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;

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

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void test() {
  int n;
  cin >> n;
  set<int> UNION;
  vector<vector<int>> vec;
  set<set<int>> U;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> dx;
    set<int> Z;
    for (int j = 0; j < k; j++) {
      int dy;
      cin >> dy;
      dx.push_back(dy);
      UNION.insert(dy);
      Z.insert(dy);
    }
    U.insert(Z);
    vec.push_back(dx);
  }
  int mx = 0;
  vector<int> Union;
  for (auto it = UNION.begin(); it != UNION.end(); it++) {
    int elem = *it;
    Union.push_back(elem);
  }
  vector<vector<int>> X;
  for (const auto &inner_set : U) {
    vector<int> x;
    for (const auto &element : inner_set) {
      x.push_back(element);
    }
    X.push_back(x);
  }
  vector<vector<int>> f(100, vector<int>(100, 0));

  for (int i = 0; i < Union.size(); i++) {
    int elem = Union[i];
    for (int j = 0; j < X.size(); j++) {
      for (int k = 0; k < X[j].size(); k++) {
        if (X[j][k] == elem) {
          f[j][elem] += 1;
        }
      }
    }
  }
  for (int i = 0; i < Union.size(); i++) {
    int elem = Union[i];
    vector<vector<int>> temp = f;
    vector<int> li;
    set<int> ans;
    for (int j = 0; j <= 50; j++) {
      int ct = 0;
      for (int k = 0; k <= 50; k++) {
        if (f[j][elem] >= 1) {
          // debug(f[j][elem], j);
          continue;
        } else {
          ct += f[j][k];
          if (f[j][k]) {
            ans.insert(k);
          }
        }
      }
      // debug(ans, elem);
      int DX = ans.size();
      mx = max(mx, DX);
    }
  }
  cout << mx << nline;
}

int32_t main() {
  fastio();
  int t;
  cin >> t;
  W(t) { test(); }
}

