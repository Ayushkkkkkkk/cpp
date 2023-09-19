#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;


void solve() {
	int n ; cin >> n ;
	vector<int> p , r;
	for (int i = 1 ; i <= n ; i++){
		p.push_back(i);
	}
	r = p;
	reverse(r.begin() , r.end());
	for (int i = 0 ; i < r.size() ; i++){
		p.push_back(r[i]);
	}
	for (int i = 0 ; i < n;  i++){
		cout << p[i] << nline;
	}
}

int main() {
	int t ; cin >> t;
	while (t--) {
		solve();
	}
}