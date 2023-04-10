#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];

vector<vector<int>> cc;
vector<int> current_cc;

bool dfs(int vertex , int par) {
	visited[vertex] = true;

	current_cc.push_back(vertex);
	bool exists = false;

	for (int child : g[vertex]) {
		if (visited[child] && child == par)
			if (visited[child])
				return true;;
		exists |=dfs(child , vertex);
	}
	
	return exists;
}

void solve() {

}


int main() {
	solve();
}