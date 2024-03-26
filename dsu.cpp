#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;

int parent[N];
int sz[N];// size

void make(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find(int v){
	if (v == parent[v]){
		return v;
	}
	// path compression
	return parent[v] = find(parent[v]);
}

void Union(int a , int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a , b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

//time complexity O(alpha(n)) amotratized time complexity lower than O(logn) almost constant


void solve(){
	int n , k ; 
	cin >> n >> k ;
	for (int i = 1 ;  i <= n ; i++){
		make(i);
	}
	while(k--){
		int u , v ; cin >> u >> v;
		Union(u , v);
	}
	int connected_ct =  0;
	for (int i = 1 ; i <= n ; i++){
		if(find(i) == i){
			connected_ct++;
		}
	}
}

int main(){
	solve();
}