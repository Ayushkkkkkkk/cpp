#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	int a[N];
	int n ; scanf("%d" , &n);
	for (int i = 0 ; i < n ; i++){
		scanf("%d" , &a[i]);
	}
	int Xor = 0;
	for (int i = 0 ; i < n ; i++){
		Xor ^= a[i];
	}
	cout << Xor;
}

int main(){
	solve();
}