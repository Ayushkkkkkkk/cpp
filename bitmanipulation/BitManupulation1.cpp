#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


int sum(int a , int b){
	int ans = 0;
	int c = 0 ;
	int pos = 0 ;
	while(a !=0 || b != 0){
		int x  = a % 2 ; int y = b % 2;
		int one = 0;
		if(x == 1)
			one++;
		if(y == 1)
			one++;
		if(c == 1)
			one++;
		c = one / 2;
		if(one % 2)
			ans = ans ^ (1 << pos);
		a =  a >> 1 , b = b >> 1;
		pos++;
	}
	if(c == 1)
		ans = ans ^ (1 << pos);
	
	return ans;
}

void solve(){
	int a , b ; cin >> a >> b;
	sum(a , b);
}

int main(){
	solve();
}