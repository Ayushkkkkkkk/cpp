#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


const int N = 1e6 + 10;
int isprime[N];
int pp[N];

void seive(){
	int maxN = 1e6;
	
	for (int i = 1 ; i <= maxN ; i++){
		isprime[i] = 1;
	}
	isprime[0] = isprime[1] = 0;
	for (int i = 2 ; i * i <= maxN ; i++){
		if(isprime[i]){
			for (int j = i * i ; j <= maxN ; j+=i){
				isprime[j] = 0;
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0 ; i < maxN ; i++){
		if(isprime[i]){
			cnt++;
		}
		
		if(isprime[cnt]==1){
			pp[i] = 1;
		}
		else
			pp[i] = 0;
	}
	
	for (int i = 1 ; i < maxN ; i++){
		pp[i] += pp[i - 1];
	}
}

void solve(){
	seive();
	int l , r , t;
	cin >> t;
	while(t--){
		cin >> l >> r;
		int cnt = 0 ;
		int cnt = pp[r] - pp[l - 1];
	}
}

int main(){
	solve();
}