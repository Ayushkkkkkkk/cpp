#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nline '\n'

const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
	visited[vertex] = true;
	
	current_cc.push_back(vertex);
	
	for (int child : g[vertex]){
		if(visited[child])
			continue;
		dfs(child);
	}
}


void solve(){
	int n , e;  cin >> n >> e;
	
	for (int i = 0 ; i < n; i++){
		int x , y ; cin >> x >> y;
		
		g[x].push_back(y);
		g[y].push_back(y);
	}
	
	
	int count = 0 ;
	for (int i = 1 ; i <= n ; i++){
		if(visited[i])
			continue;
		
		current_cc.clear();
		dfs(i);
		cc.push_back(current_cc);
		count++;
	}
	cout << count << nline;
}


int main(){
	solve();	
}