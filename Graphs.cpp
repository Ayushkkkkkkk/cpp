#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


const int N = 1e3 + 10;
// space complexity is high o(n^2)
// if n > 10^6  we cannot't store in a 2d matrix
int graph[N][N];
// space complexity o(n + m);
vector<int> graph2[N];
vector<pair<int , int>> graphWeight[N];

void weightedGraph(){
	int n , m ; cin >> n >> m ;
}


void adjacentListRepresentation(){
	int n , m ; cin >> n >> m ;
	
	for (int i = 0 ; i < m ; ++i){
		int v1 , v2 , wt; cin >> v1 >> v2 >> wt;
		
		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
		
		graphWeight[v1].push_back(make_pair(v2 , wt));
		graphWeight[v2].push_back(make_pair(v1 , wt));
		
		// checking if connected
		
		// for (pair<int , int>  child : graph2) if(child.first == j) child.second = 
	}
}

void ajdacentMatrixRepresentation() {
	// i , j is connected not not 
	
	// if(graph[i][j] == 1) connected
	
	
	int n , m ;
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		int v1 , v2 , wt ;
		cin >> v1 >> v2 >> wt;

		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
		
		graph[v1][v2] = wt;
		graph[v2][v1] = wt;
	}
}

int main() {
	
}