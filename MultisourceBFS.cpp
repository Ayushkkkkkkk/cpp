#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
int lev[N][N];
int vis[N][N];

int n  , m ;

vector<pair<int , int>> dxdy = {
	{0 , 1} , {0 , -1} , {1 , 0} , { -1 , 0},
	{1 ,1} , {1 ,-1} , {-1 , 1} , {-1 , -1}
};

bool isValid(int i , int j ) {
	return i >= 0 && j >= 0 && i < n && j < m ;
}

int bfs() {
	int mx = 0 ;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			mx = max(mx , val[i][j]);
		}
	}
	queue<pair<int , int>> q;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			if (mx == val[i][j]) {
				q.push({i , j});
				lev[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}
	
	int ans = 0;
	while (!q.empty()) {
		pair<int , int> v = q.front();
		int v_x = v.first;
		int v_y = v.second;
		q.pop();

		for (pair<int , int> dx : dxdy) {
			int child_x = dx.first + v_x;
			int child_y = dx.second + v_y;

			if (!isValid(child_x , child_y))
				continue;
			if (vis[child_x][child_y]) {
				continue;
			}

			q.push({child_x , child_y});
			lev[child_x][child_y] = lev[v_x][v_y] + 1;
			vis[child_x][child_y] = true;
			ans = max(ans , lev[child_x][child_y]);	
		}

	}
	return ans;
}

void reset() {
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			vis[i][j] = 0;
			lev[i][j] = INF;
		}
	}
}

void solve() {
	reset();
	cin >> n >> m ;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			cin >> val[i][j];
		}
	}
	cout << bfs() << nline;
}

int main() {
	int t ; cin >> t;
	while (t--) {
		solve();
	}
}