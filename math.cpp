#include<bits/stdc++.h>

using namespace std;

const int S = 4e5 + 5, Inf = 0x3f3f3f3f;
int pw5[10] = {}, dp[S] = {};
queue<int> Q;

inline void checkmin(int &x, int y){
	if(y < x) x = y;
}

inline int w(int mask, int i){
	return (mask / pw5[i]) % 5;
}

inline int f(int a, int b, int m){
	return (a << 2) | (b << 1) | m;
}

inline int g(int c, int d){
	return (c << 1) | d;
}

inline int work(int mask, int opt){
	int ret = 0;
	for(int a = 0 ; a < 2 ; a ++) for(int b = 0 ; b < 2 ; b ++) for(int m = 0 ; m < 2 ; m ++){
		int x = w(mask, f(a, b, m)), c = x >> 1, d = x & 1;
		if(opt == 1) c = c & d;
		else if(opt == 2) c = c | d;
		else if(opt == 3) d = c ^ d;
		else d = m ^ d;
		ret += pw5[f(a, b, m)] * g(c, d);
	}
	return ret;
}

inline void init(){
	pw5[0] = 1;
	for(int i = 1 ; i <= 8 ; i ++) pw5[i] = pw5[i - 1] * 5;
	memset(dp, 0x3f, sizeof(dp));
	int mask = 0;
	for(int a = 0 ; a < 2 ; a ++) for(int b = 0 ; b < 2 ; b ++) for(int m = 0 ; m < 2 ; m ++) mask += pw5[f(a, b, m)] * g(a, b);
	dp[mask] = 0, Q.push(mask);
	while(Q.size()){
		int s = Q.front(); Q.pop();
		for(int opt = 0 ; opt < 4 ; opt ++){
			int t = work(s, opt);
			if(dp[t] == Inf) dp[t] = dp[s] + 1, Q.push(t);
		}
	}
	for(int mask = 0 ; mask < pw5[8] ; mask ++) for(int i = 0 ; i < 8 ; i ++) if(w(mask, i) == 4){
		for(int x = 1 ; x <= 4 ; x ++) checkmin(dp[mask], dp[mask - x * pw5[i]]);
		break;
	}
}

inline void solve(){
	int A = 0, B = 0, C = 0, D = 0, M = 0, mask = pw5[8] - 1;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &M);
	for(int i = 0 ; i < 30 ; i ++){
		int a = (A >> i) & 1, b = (B >> i) & 1, c = (C >> i) & 1, d = (D >> i) & 1, m = (M >> i) & 1;
		if(w(mask, f(a, b, m)) == 4) mask -= (4 - g(c, d)) * pw5[f(a, b, m)];
		else if(w(mask, f(a, b, m)) != g(c, d)){
			printf("-1\n");
			return;
		}
	}
	printf("%d\n", (dp[mask] < Inf) ? dp[mask] : -1);
}

int T = 0;

int main(){
	init();
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}