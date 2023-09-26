#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
void solve(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(ll& x : A) cin >> x;
	A.push_back(0);
	N++;
	ll ans = 0;
	for(int j = 2; j < N; j++){
		ans += max(A[j], ll(0));
	}
	ans += max({ll(0), A[0], A[0] + A[1]});
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}