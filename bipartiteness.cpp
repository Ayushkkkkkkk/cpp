#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;

void dfs(int sv , int p  , vector<vector<int>> &v , int dep , int &c1 , int &c2){
	if(dep % 2) c1++;
	else
		c2++;
	
	for (int i = 0 ; i < v[sv].size();i++){
		if(v[sv][i] == p) continue;
		
		dfs(v[sv][i] , sv , v , dep + 1 , c1 , c2);
	}
}


void solve(){
	int n ; cin >> n ;
	vector<vector<int>> v(n + 1);
	int c1 = 0 , c2 = 0;
	
	for (int i = 0 ; i < n ; i++){
		int x , y ; cin >> x >> y ;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1 , -1 , v , 0 , c1 , c2);
	cout << (c1 * c2) - n + 1 << endl;
}

int main(){
	solve();
}