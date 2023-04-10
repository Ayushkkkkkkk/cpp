#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

ll ar[3];

ll I[3][3] , T[3][3];


void mul(ll A[3][3] , ll B[3][3] , int dim){
	ll res[dim + 1][dim + 1];
	
	for (int i = 1 ; i <= dim ; i++){
		for (int j = 1 ; j <= dim ; j++){
			res[i][j] = 0;
			for (int k = 1 ; k <= dim ; k++){
				//res[i][j] += A[i][k] * B[k][j];
				ll x = (A[i][k] * B[k][j]) % MOD;
				res[i][j] = (res[i][j] + x) % MOD;
			}
		}
	}
	for (int i = 1 ; i <= dim ; i++){
		for (int j = 1 ; j <= dim ; j++){
			A[i][j] = res[i][j];
		}
	}
}


ll getFib(int n){
	if (n <= 2){
		return ar[n];
	}
	
	I[1][1] = I[2][2] = 1;
	I[1][2] = I[2][1] = 0;
	
	T[1][1] = 0;
	T[1][2] = T[2][1] = T[2][2] = 1;
	
	n = n - 1;
	
	while(n){
		if(n % 2){
			mul(I , T , 2);
			n--;
		}
		else{
			mul(T , T , 2) , n /= 2;
		}
	}
	ll Fn = (ar[1] * I[1][1] + ar[2] * I[2][1]) % MOD;
	return Fn;
	
}


void solve(){
	int t  ,  n ;
	cin >> t;
	while(t--){
		cin >> ar[1] >> ar[2] >> n ; n++;
		cout << getFib(n) << nline;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}