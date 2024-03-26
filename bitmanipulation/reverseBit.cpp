#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


void solve(){
	unsigned int A; cin >> A;
	unsigned int ans = 0;
	int position = 0;
	while(A!=0){
		if(A % 2){
			ans = ans + (1 << (31 - position));
		}
		A = A >> 1;
	}
}

int main(){
	solve();
}