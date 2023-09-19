#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int N = 1e5 + 10;


int lcm(int a , int b){
	return a * b / __gcd(a , b);
}

void solve(int i){
	int n = i;
	for (int i = 1 ; i <= n ; i++){
		cout << lcm(i , n) << " ";
	}
	cout << nline;
}

int main(){
	for (int i = 1 ; i <= 200 ; i++){
		solve(i);
	}
}