#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	int n ; cin >> n ;
	vector<int> a(n);
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	int ans = 0 ;
	for (int i = 31 ; i >= 0 ; i--){
		int set =0 , unset = 0;
		for (int j = 0 ; j < N ; j++){
			if(a[j] & (1 << i)){
				set++;
			}
			else{
				unset++;
			}
		}
		ans += (set * unset) % 1000000007;
	}
}

int main(){
	solve();
}