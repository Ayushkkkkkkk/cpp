#include<bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;
int n = 5000, m = 0;
vector<vector<int> > G(N), Gx(N);
long double f[N] = {}, g[N][N] = {};

inline bool cmp(int u, int v){
	return f[u] > f[v];
}

inline void work(int u){
	if(u == n){
		f[u] = 1.00;
		return;
	}
	sort(G[u].begin(), G[u].end(), cmp);
	int k = G[u].size();
	for(int i = 0 ; i < k ; i ++){
		int v = G[u][i];
		f[u] += f[v] * g[k][i + 1];
	}
}

inline void init(){
	for(int u = 1 ; u <= n ; u ++){
		f[u] = 0.00;
		G[u].clear(), Gx[u].clear();
	}
	n = m = 0;
}

inline void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1, u = 0, v = 0 ; i <= m ; i ++){
		scanf("%d %d", &u, &v);
		if(u != n){
			G[u].push_back(v);
			Gx[v].push_back(u);
		}
	}
	for(int u = n ; u >= 1 ; u --) work(u);
	printf("%.12Lf\n", f[1]);
}

int T = 0;

int main(){
	for(int i = 1 ; i <= n ; i += 2) for(int j = 1 ; j <= i ; j ++) g[i][j] = 1.00 / i;
	for(int i = 2 ; i <= n ; i += 2){
		g[i][1] = 1.00;
		for(int j = 1 ; j <= i ; j ++) g[i][j] /= i;
		if(i + 2 <= n) for(int j = 1 ; j <= i ; j ++) g[i + 2][j + 1] += g[i][j] * (i - j + 1), g[i + 2][j + 2] += g[i][j] * j;
	}
	scanf("%d", &T);
	for(int i = 1 ; i <= T ; i ++) init(), solve();
	return 0;
}