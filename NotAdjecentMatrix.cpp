#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nline '\n'

void solver() {
	ll n ; cin >> n;
	if (n == 1) {
		cout << 1 << nline;
		return;
	}
	if (n == 2) {
		cout << -1 << nline;
		return;
	}
	int board[n][n];
	if ((n & 1) == 1) {
		int even = (n * n) / 2;
		int odd = (n * n)  - even;
		int oddNum = 1;
		int evenNum = 2;
		int odd_count = 0;
		int even_count = 0;
		int count = 1;
		for (int i = 0 ; i < n ; i++) {
			for (int j  = 0 ; j < n ; j++) {
				if (odd_count < odd) {
					board[i][j] = oddNum;
					oddNum += 2;
					odd_count++;
				}
				else {
					board[i][j] = evenNum;
					evenNum += 2;
					even_count++;
				}
			}
		}
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < n ; j++) {
				cout << board[i][j] << " ";
			}
			cout << nline;
		}
	}
	else {
		int even = (n * n) / 2;
		int odd = (n * n)  / 2;
		int oddNum = 1;
		int evenNum = 2;
		int odd_count = 0;
		int even_count = 0;
		int count = 1;
		for (int i = 0 ; i < n ; i++) {
			for (int j  = 0 ; j < n ; j++) {
				if (odd_count < odd) {
					board[i][j] = oddNum;
					oddNum += 2;
					odd_count++;
				}
				else {
					board[i][j] = evenNum;
					evenNum += 2;
					even_count++;
				}
			}
		}
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < n ; j++) {
				cout << board[i][j] << " ";
			}
			cout << nline;
		}
	}
}



int main() {
	int tt ; cin >> tt;
	while (tt--) {
		solver();
	}
}