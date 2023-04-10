#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


const int N = 1e5 + 10;
vector<int> g[N];
bool vistied[N];
int level[N];

void bfs(int source) {
	queue<int> q;
	q.push(source);
	vistied[source] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cerr << current << nline;
		for (int child : g[current]) {
			if (!vistied[child]) {
				q.push(child);
				vistied[child] = 1;

				level[child] = level[current] + 1;
			}
		}
	}
}

void solve() {
	int n ; cin >> n ;
	for (int i = 0 ; i < n - 1 ; i++) {
		int x , y ; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1);
}



int main() {
	solve();
}