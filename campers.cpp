#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
//const int N = 1e5 + 10;

int parent[N];
int sz[N];// size
multiset<int> sizes;

void make(int v){
	parent[v] = v;
	sz[v] = 1;
	sizes.insert(1);
}

int find(int v){
	if (v == parent[v]){
		return v;
	}
	// path compression
	return parent[v] = find(parent[v]);
}

void merge(int a , int b){
	sizes.erase(sizes.find(sz[a]));
	sizes.erase(sizes.find(sz[b]));
	sizes.insert(sz[a] + sz[b]);
}

void Union(int a , int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a , b);
		}
		parent[b] = a;
		merge(a , b);
		sz[a] += sz[b];
	}
}

void solve(){
	int n , q;  cin >> n >> q;
	for (int i = 1 ; i <= n ; i++){
		make(i);
	}
	while(q--){
		int u , v ; cin >> u >> v;
		Union(u , v);
		if(sizes.size() == 1){
			cout << 0 << nline;
		}
		else{
			int mini = *(sizes.begin());
			int maxi = *(--sizes.end());
			cout << maxi - mini << nline;
		}
	}
	
}

int main(){
	solve();
}