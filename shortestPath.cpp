#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define nline '\n'

const int N = 1e5 + 10;
vector<int> g[N];
int vis[8][8];
int lev[8][8];



int getX(string s){
	return s[0] - 'a';
}

int getY(string s){
	return s[1] - '0';
}


int bfs(string source , string dest){
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int desty = getY(dest);
	queue<pair<int , int>> q;
	q.push({sourceX , sourceY});
	vis[sourceX][sourceY] = 1;
	
	while(!q.empty()){
		pair<int , int> v = q.front();
		int x = v.first , y = v.second;
		q.pop();
		
		
		
		
	}
}

void reset(){
	for (int i = 0 ; i < 8 ; i++){
		for (int j = 0 ; j < 8 ; j++){
			lev[i][j] = 0;
			vis[i][j] = 0;
		}
	}
}



void solve(){
	int n ; cin >> n ;
	while(n--){
		reset();
		string s1 , s2 ; cin >> s1 >> s2;
		cout << bfs(s1 , s2);
	}
}


int main(){
	solve();
}