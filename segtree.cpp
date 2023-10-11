#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3003;
 
int n;
int k[4];
vector<int> a[4];
 
struct segtree {
  int sz;
  int tot;
  vector<int> t, p;
  
  segtree(int sz) : sz(sz) {
    tot = 0;
    t = vector<int>(4 * sz);
    p = vector<int>(4 * sz);
    build(0, 0, sz);
  }
  
  void build(int v, int l, int r) {
    if (l + 1 == r) {
      t[v] = -l;
      return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
  
  void push(int v) {
    if (p[v] == 0) return;
    if (v + 1 < 2 * sz) {
      t[v * 2 + 1] += p[v];
      p[v * 2 + 1] += p[v];
      t[v * 2 + 2] += p[v];
      p[v * 2 + 2] += p[v];
      p[v] = 0;
    }
  } 
  
  void upd(int v, int l, int r, int L, int R, int x) {
    if (L >= R) return;
    if (l == L && r == R) {
      t[v] += x;
      p[v] += x;
      return;
    }
    push(v);
    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, L, min(m, R), x);
    upd(v * 2 + 2, m, r, max(L, m), R, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
  
  void upd(int pos, int x) { 
    tot += x;
    upd(0, 0, sz, max(0, pos), sz, x);
  }
  
  int get(int v, int l, int r, int L, int R) {
    if (L >= R) return -1e9;
    if (l == L && r == R) return t[v];
    push(v);
    int m = (l + r) / 2;
    return max(
      get(v * 2 + 1, l, m, L, min(m, R)),
      get(v * 2 + 2, m, r, max(L, m), R)
    );
  }
  
  int get(int L) {
    return get(0, 0, sz, max(0, L), sz);
  }
  
  int getBad(int v, int l, int r) {
    if (t[v] <= 0) return -1;
    if (l + 1 == r) return l;
    push(v);
    int m = (l + r) / 2;
    if (t[v * 2 + 1] > 0) {
      return getBad(v * 2 + 1, l, m);
    } else {
      return getBad(v * 2 + 2, m, r);
    }
  }
  
  int getBad() {
    return getBad(0, 0, sz);
  }
};  
 
int main() {
  cin >> n;
  int sz = 1;
  for (int i = 0; i < n; ++i) {
    int t, s;
    cin >> t >> s;
    a[t].push_back(s);
    sz = max(sz, s + 1);
  }
  for (int t = 1; t < 4; ++t) {
    sort(a[t].begin(), a[t].end());
    k[t] = a[t].size();
  }
  reverse(a[2].begin(), a[2].end());
  int ans = 1e4;
  for (int len = 1; len <= k[2] + k[3] + 1; ++len) {
    segtree L(sz), R(sz);
    multiset<int> used;
    for (int x : a[1]) L.upd(x, +1);
    for (int x : a[2]) R.upd(x, +1);
    for (int x : a[3]) {
      L.upd(x - len, +1);
      if (L.t[0] <= 0) {
        used.insert(x - len);
      } else {
        L.upd(x - len, -1);
        L.upd(x, +1);
        R.upd(x, +1);
      }
    }
    for (int i = 0; i <= k[2]; ++i) {
      if (L.t[0] <= 0 && R.t[0] <= 0 && R.tot + 1 <= len)
        ans = min(ans, n + (k[3] - (int)used.size()) + 2); 
      if (i == k[2]) break;
      R.upd(a[2][i], -1);
      L.upd(a[2][i] - len, +1);
      int pos;
      while ((pos = L.getBad()) != -1) {
        auto it = used.upper_bound(pos);
        if (it == used.begin()) break;
        --it;
        L.upd(*it, -1);
        L.upd(*it + len, +1);
        R.upd(*it + len, +1);
        used.erase(it);
      }
    }
  }
  if (ans == 1e4) ans = -1;
  cout << ans << '\n';
}