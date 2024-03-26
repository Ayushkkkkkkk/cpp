#include<bits/stdc++.h>

using namespace std;

const int N = 3000 + 5;
const long double Inf = 1e18;
int n = 0, m = 0;
long double dp[N][N] = {};

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i <= n ; i ++) for(int x = 0 ; x <= m ; x ++) dp[i][x] = Inf;
	dp[0][0] = 0.00;
	for(int i = 1 ; i <= n ; i ++) for(int x = 0 ; x <= m ; x ++) for(int y = 1 ; x + y * (n - i + 1) <= m ; y ++) dp[i][x + y] = min(dp[i][x + y], dp[i - 1][x] + 1.00 * x / y);
	printf("%.12Lf", 2 * dp[n][m] + n);
	return 0;
}