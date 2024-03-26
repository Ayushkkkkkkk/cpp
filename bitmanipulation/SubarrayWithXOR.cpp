#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	int n , b ; cin >> n >> b;
	int A[n];
	for (int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	map<int , int> mp;
	int ans = 0;
	mp[0] = 1;
	int prefix = 0;
	for (int i = 0 ; i < n ; i++){
		prefix = prefix ^ A[i];
		int target = prefix ^ b;
		if(mp.count(target))
			ans += mp[target];
	}
	cout << ans << nline;
}

int main(){
	solve();
}