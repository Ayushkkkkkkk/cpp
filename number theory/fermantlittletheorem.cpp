#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;



long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
	int t , a , b , m ; 
	cin >> t;
	while(t--){
		cin >> a >> m ;
		cout << "a^-1" <<" "<< power(a , m - 2 , m) << nline;
	}
}

int main(){
	solve();
}