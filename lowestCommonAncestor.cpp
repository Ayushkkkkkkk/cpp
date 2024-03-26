#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
vector<int> g[N];

int parent[N];

void dfs(int v , int p = -1) {
	parent[v] = p;
	for (int child : g[v]) {
		if (child == p) continue;
		dfs(child , v);
	}
}

vector<int> path(int v) {
	vector<int> ans;
	while (v != -1) {
		ans.push_back(v);
		v = parent[v];
	}
	reverse(ans.begin() , ans.end());
	return ans;
}


void solve() {
	int n ; cin >> n ;
	for (int i = 0 ; i < n - 1 ; i++) {
		int x , y ; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	int x , y ; cin >> x >> y ;
	vector<int> path_x = path(x);
	vector<int> path_y = path(y);

	int mini = min(path_x.size() , path_y.size());

	int lca = -1;

	for (int i = 0 ; i < mini ; ++i) {
		if (path_x[i] == path_y[i]) {
			lca = path_x[i];
		}
		else {
			break;
		}
	}

	cout << lca << nline;

}

int main() {
	solve();
}