#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;

#define all(x) (x).begin(), (x).end()

#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}


vector<ll> primes;
bool ar[90000001];

void seive(){
	int maxN = 90000000;
	ar[0] = ar[1] = true;
	
	for (int i = 2 ; i * i < maxN ; i++){
		if(!ar[i]){
			for (int j = i * i ; j <= maxN ; j+=i){
				ar[i] = true;
			}
		}
	}
	for (int i = 2 ; i <= maxN ; i++){
		if(!ar[i]){
			primes.push_back(i);
		}
	}
}



void solve(){
	int q , n;
	cin >> q >> n ;
	seive();
	while(q--){
		cin >> n , cout << primes[n - 1] << nline;
	}
}

int main(){
	solve();
}