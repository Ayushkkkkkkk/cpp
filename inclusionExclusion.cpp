#include<bits/stdc++.h>
#define MAXN 1000
#define MODD 998244353
#define ll long long
using namespace std;

ll fact[MAXN*MAXN+2];
ll factinv[MAXN*MAXN+2];
ll modpow(ll x, ll y) {
    ll xs = x;
    ll answer = 1;
    while(y) {
        if (y&1) {
            answer = (answer * xs) % MODD;
        }
        y >>= 1;
        xs = (xs * xs) % MODD ;
    }
    return answer;
}

ll B(ll x, ll y) {
	if (x < y) return 0;
	if (y == 0) return 1;
	return fact[x]*factinv[y]%MODD*factinv[x-y]%MODD;
}

ll ways[MAXN+1][MAXN+1];
ll C[4][MAXN+1][MAXN+1];
int main() {
	int H,W,K;
	cin>>H>>W>>K;
	fact[0]=factinv[0]=1;
	for(int i=1;i<=H*W;i++) {
		fact[i]=(fact[i-1]*i)%MODD;
		factinv[i]=modpow(fact[i],MODD-2);
	}
	ll ans=0;
	for(int h=1;h<=H;h++) {
		for(int w=1;w<=W;w++) {	
			ll ways_to_enclose_smaller=0;
			ways_to_enclose_smaller += (h+1)*(w+1)*(C[0][h-1][w]+C[0][h][w-1]-C[0][h-1][w-1]);
			ways_to_enclose_smaller -= (h+1)*(C[1][h-1][w]+C[1][h][w-1]-C[1][h-1][w-1]);
			ways_to_enclose_smaller -= (w+1)*(C[2][h-1][w]+C[2][h][w-1]-C[2][h-1][w-1]);
			ways_to_enclose_smaller += (C[3][h-1][w]+C[3][h][w-1]-C[3][h-1][w-1]);
			ways_to_enclose_smaller %= MODD;
			ways[h][w]=B(h*w,K)-ways_to_enclose_smaller;
			ways[h][w]%=MODD;
			if (ways[h][w]<0)ways[h][w]+=MODD;
			ans += h*w*(H-h+1ll)*(W-w+1ll)%MODD*ways[h][w]%MODD;
			ans %= MODD;
			C[0][h][w]=ways[h][w]+C[0][h-1][w]+C[0][h][w-1]-C[0][h-1][w-1];
			C[1][h][w]=w*ways[h][w]+C[1][h-1][w]+C[1][h][w-1]-C[1][h-1][w-1];
			C[2][h][w]=h*ways[h][w]+C[2][h-1][w]+C[2][h][w-1]-C[2][h-1][w-1];
			C[3][h][w]=w*h*ways[h][w]+C[3][h-1][w]+C[3][h][w-1]-C[3][h-1][w-1];
			for(int j=0;j<4;j++) {
				C[j][h][w]%=MODD;
				if (C[j][h][w]<0) C[j][h][w]+=MODD;
			}
		}
	}
	cout << ans*modpow(B(H*W,K),MODD-2)%MODD << endl;
}
