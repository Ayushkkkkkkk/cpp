#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
vector<int> pre(N) , suff(N) , ar(N);


void solve(){
	int t, q , n , l , r ;
	cin >> t;
	while(t--){
		cin >> n >> q;
		for (int i = 1 ; i <= n ; i++){
			cin >> ar[i];
		}
		pre[0] = 0;
		suff[n + 1] = 0 ;
		for (int i = 1 ; i <= n ; i++){
			pre[i] = __gcd(pre[i - 1] , ar[i]);
		}
		for (int i = n ; i >= 1 ; i--){
			suff[i] = __gcd(ar[i] , suff[i + 1]);
		}
		while(q--){
			cin >> l >> r;
			cout << __gcd(pre[ l -1] , suff[r + 1])<< nline;;
		}
	}
}

int main(){
	solve();
}