#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	string s ; cin >> s;
	int n = s.size();
	if(n <= 2){
		cout << "YES" << nline;
		return;
	}
	
	vector<int> a(n);
	for (int i = 0 ; i < n ; i++){
		a[i] = s[i] - 'A';
	}
	
	vector<int> fibo(n);
	fibo[0] = a[0] , fibo[1] = a[1];
	
	bool ok = true;
	for (int i = 2 ; i < n ; i++){
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 26;
		if(a[i] != fibo[i])
			ok = false;
	}
	
	cout << (ok ? "YES" : "NO") << nline;
}

int main(){
	solve();
}