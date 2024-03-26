#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	int n ; cin >> n ;
	vector<int> A(n);
	for (int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 0 ; i < n;  i++){
		int contri = (i + 1) * (n - i);
		if(contri % 2){
			ans = ans ^ A[i];
		}
	}
}

int main(){
	solve();
}