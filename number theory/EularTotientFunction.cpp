#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;



int phi(int n){
	int res = n ;
	for (int i= 2 ; i * i <= n ; i++){
		if(n % i == 0){
			res /= i;
			res *= (i - 1);
			
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if(n > 1)
		res /= n  , res *= (n - 1);
	return res;
}

void solve() {
	int n ; cin >> n;
}

int main() {
	int  t ; cin >> t;
	while (t--) {
		solve();
	}
}