#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 200 + 5, Mod = 1e9 + 7;

inline ll power(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y & 1) ret = ret * x % Mod;
		x = x * x % Mod, y >>= 1;
	}
	return ret;
}

ll n = 0, k = 0, lim = 0;
ll C[N][N] = {}, pw[N * N][N] = {}, iv[N * N] = {}, ifac[N * N] = {}, dp[N][N * N] = {};
ll a[N * N] = {}, b[N * N] = {}, ans = 0;

int main(){
	scanf("%lld %lld", &n, &k); lim = n * (n + 1) / 2;
	for(ll i = 0 ; i <= n ; i ++){
		C[i][0] = 1;
		for(ll j = 1 ; j <= i ; j ++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	}
	ifac[0] = 1;
	for(ll x = 0 ; x <= lim ; x ++){
		pw[x][0] = 1;
		if(x) iv[x] = power(x, Mod - 2), ifac[x] = ifac[x - 1] * iv[x] % Mod;
		for(ll i = 1 ; i <= n ; i ++) pw[x][i] = pw[x][i - 1] * x % Mod;
	}
	for(ll x = 0 ; x <= lim ; x ++) dp[0][x] = 1;
	for(ll i = 1 ; i <= n ; i ++){
		for(ll j = 0 ; j < i ; j ++) for(ll x = 0 ; x <= lim ; x ++) dp[i][x] = (dp[i][x] + dp[j][x] * dp[i - 1 - j][x] % Mod * C[i - 1][j]) % Mod;
		for(ll x = 0 ; x <= lim ; x ++) dp[i][x] = dp[i][x] * pw[x][i] % Mod;
	}
	a[0] = 1;
	for(ll i = 0 ; i <= lim ; i ++){
		for(ll x = lim ; x >= 1 ; x --) a[x] = (a[x - 1] + a[x] * (Mod - i)) % Mod;
		a[0] = a[0] * (Mod - i) % Mod;
	}
	for(ll i = 1 ; i <= lim ; i ++) if(dp[n][i]){
		ll w = dp[n][i] * ifac[i] % Mod * ifac[lim - i] % Mod;
		if((lim - i) & 1) w = Mod - w;
		b[0] = a[0] * (Mod - iv[i]) % Mod;
		for(ll x = 1 ; x <= lim ; x ++) b[x] = (a[x] - b[x - 1] + Mod) * (Mod - iv[i]) % Mod;
		for(ll x = k ; x <= lim ; x ++) ans = (ans + b[x] * w) % Mod;
	}
	printf("%lld\n", ans);
	return 0;
}