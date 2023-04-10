#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

bool visited[N];

void dfs(int vertex){
	// take action on vertex after entering the vertex
	
	//if(visited[vertex]) return;
	cout << vertex << endl;
	visited[vertex] = true;
	for (int child : graph[vertex]){
		// take action on child before 
		// entering child node
		if(visited[child])
			continue;
		dfs(child);
		// take action on child after exiting child node
	}
	//take action on vertex before exiting the vertex
}


void solve(){
	int n , m ; cin >> n >> m;
	
	for (int i = 0 ; i < m ; i++){
		int v1 , v2 ; cin >> v1 >> v2;
		
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		
		
	}
}


int main(){
	solve();
}