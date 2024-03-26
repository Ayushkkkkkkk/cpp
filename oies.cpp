#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 200 + 5, Mod = 1e9 + 7;
ll n = 0, m[N] = {}, fac[N] = {}, f[N][N] = {}, g[N][N][N] = {};

int main(){
	scanf("%lld", &n);
	for(ll i = 1 ; i <= n ; i ++) scanf("%lld", &m[i]);
	if(m[1] == n){
		printf("0");
		return 0;
	}
	fac[0] = 1;
	for(ll i = 1 ; i <= n ; i ++) fac[i] = fac[i - 1] * i % Mod;
	for(ll i = 1 ; i <= n ; i ++) g[i][i - 1][0] = 1;
	for(ll l = n ; l >= 1 ; l --) for(ll r = l ; r <= n ; r ++){
		for(ll x = 1 ; x <= r - l + 1 ; x ++) g[l][r][x] = g[l][r - 1][x - 1];
		for(ll mid = l ; mid < r ; mid ++) if(r <= m[mid + 1]) for(ll x = 0 ; x <= mid - l + 1 ; x ++) g[l][r][x] = (g[l][r][x] + g[l][mid][x] * (Mod - f[mid + 1][r])) % Mod;
		for(ll x = 0 ; x <= r - l + 1 ; x ++) f[l][r] = (f[l][r] + g[l][r][x] * fac[x]) % Mod;
		if(r <= m[l]) g[l][r][0] = (g[l][r][0] + (Mod - f[l][r])) % Mod;
	}
	printf("%lld", f[1][n]);
	return 0;
}