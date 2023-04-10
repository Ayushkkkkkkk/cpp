#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e6 + 10;

bool isprime[N];

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
}

void solve(){
	
}

int main(){
	solve();
}