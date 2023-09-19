#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	int n ; cin >> n ;
	vector<int> A(n);
	for(auto &it: A){
		cin >> it;
	}
	int ans = 0;
	for(int i = 30 ; i >= 0 ; i--){
		int c = 0;
		for (int j = 0; j < A.size() ; j++){
			if(A[j] & (1 << i)){
				c++;
			}
		}
		if(c % 3 != 0) ans += (1 << i);
	}
}

int main(){
	solve();
}