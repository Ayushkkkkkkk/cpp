#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;

void primeFact(int Nx){
	for (int i = 2 ; i <= Nx ; i++){
		if( Nx % i == 0){
			int cnt = 0 ;
			while(N % i == 0){
				cnt++ , Nx/=i;
				cout << i << "^" << cnt << nline;
			}
		}
		if(Nx > 1){
			cout << Nx << "^" <<1<< nline;
		}
	}
}


void solve(){
	
}

int main(){
	solve();
}