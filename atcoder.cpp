#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll n, m;
vector<int> G[200005];
int color[200005];

P dfs(int v, int p, int c){
  P ret = P(0, 0);
  color[v] = c;
  
  if(c == 1) ret.first++;
  else ret.second++;
  
  for(auto u : G[v]){
    if(u == p || color[u] == -c) continue;
    if(color[u] == c) return P(-1, -1);
    P res = dfs(u, v, -c);
    if(res.first == -1) return P(-1, -1);
    ret.first += res.first, ret.second += res.second;
  }
  return ret;
}

int main(void)
{
  cin >> n >> m;
  int u, v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  ll ans = n*(n-1)/2 - m;
  for(int i = 1; i <= n; i++){
    if(!color[i]){
      P res = dfs(i, -1, 1);
      if(res.first == -1){
        cout << 0 << endl;
        return 0;
      }
      ans -= res.first * (res.first-1) / 2;
      ans -= res.second * (res.second-1) / 2;
    }
  }
  cout << ans << endl;
  
  return 0;
}
