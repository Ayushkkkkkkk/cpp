#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
const int LOG = 18;
struct S{
  int sz;
  long long sum;
  S(){
  }
  S(int x): sz(1), sum(x){
  }
};
S op(S L, S R){
  S ans;
  ans.sz = L.sz + R.sz;
  ans.sum = L.sum + R.sum;
  return ans;
}
S e(){
  S ans;
  ans.sz = 0;
  ans.sum = 0;
  return ans;
}
S mp(int f, S x){
  x.sum += (long long) f * x.sz;
  return x;
}
int comp(int f, int g){
  return f + g;
}
int id(){
  return 0;
}
int main(){
  int N;
  cin >> N;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);
  for (int i = 0; i < Q; i++){
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  vector<int> d(N, 0);
  vector<int> in(N), out(N);
  int t = 0;
  auto dfs = [&](auto dfs, int v = 0) -> void {
    in[v] = t;
    t++;
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        dfs(dfs, w);
      }
    }
    out[v] = t;
  };
  dfs(dfs);
  vector<vector<int>> pp(LOG, vector<int>(N, -1));
  pp[0] = p;
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < N; j++){
      if (pp[i][j] != -1){
        pp[i + 1][j] = pp[i][pp[i][j]];
      }
    }
  }
  auto la = [&](int v, int k){
    for (int i = 0; i < LOG; i++){
      if ((k >> i & 1) == 1){
        v = pp[i][v];
      }
    }
    return v;
  };
  vector<int> X(Q);
  for (int i = 0; i < Q; i++){
    if (d[L[i]] > d[R[i]]){
      swap(L[i], R[i]);
    }
    int u = L[i], v = R[i];
    int lca;
    v = la(v, d[v] - d[u]);
    if (u == v){
      lca = u;
    } else {
      for (int j = LOG - 1; j >= 0; j--){
        if (pp[j][u] != pp[j][v]){
          u = pp[j][u];
          v = pp[j][v];
        }
      }
      lca = p[u];
    }
    int dist = d[L[i]] + d[R[i]] - 2 * d[lca];
    if (L[i] != R[i]){
      X[i] = la(R[i], (dist - 1) / 2);
    }
  }
  vector<vector<int>> query1(N), query2(N), query3(N);
  for (int i = 0; i < Q; i++){
    if (L[i] != R[i]){
      query1[L[i]].push_back(i);
      query2[R[i]].push_back(i);
    } else {
      query3[L[i]].push_back(i);
    }
  }
  atcoder::lazy_segtree<S, op, e, int, mp, comp, id> ST(N);
  for (int i = 0; i < N; i++){
    ST.set(in[i], S(d[i]));
  }
  vector<long long> ans(Q, 0);
  auto dfs2 = [&](auto dfs2, int v = 0) -> void {
    for (int i : query1[v]){
      ans[i] += ST.prod(0, in[X[i]]).sum;
      ans[i] += ST.prod(out[X[i]], N).sum;
    }
    for (int i : query2[v]){
      ans[i] += ST.prod(in[X[i]], out[X[i]]).sum;
    }
    for (int i : query3[v]){
      ans[i] += ST.prod(0, N).sum;
    }
    for (int w : c[v]){
      ST.apply(in[w], out[w], -1);
      ST.apply(0, in[w], 1);
      ST.apply(out[w], N, 1);
      dfs2(dfs2, w);
      ST.apply(in[w], out[w], 1);
      ST.apply(0, in[w], -1);
      ST.apply(out[w], N, -1);
    }
  };
  dfs2(dfs2);
  for (int i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }
}