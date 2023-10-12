#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(n), b(m);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, m) scanf("%d", &b[i]);
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&a](int i, int j) {
		return a[i] > a[j];
	});
	vector<vector<int>> mn(m, vector<int>(n + 2));
	forn(i, m) {
		int r = 0;
		forn(l, n + 2) {
			r = min(n + 1, max(r, l + 1));
			while (r <= n && a[ord[r - 1]] * (r - l) < b[i]) ++r;
			mn[i][l] = r;
		}
	}
	vector<int> dp(1 << m, n + 1);
	dp[0] = 0;
	vector<int> p(1 << m, -1);
	forn(mask, 1 << m) forn(i, m) if (!((mask >> i) & 1) && dp[mask | (1 << i)] > mn[i][dp[mask]]) {
		dp[mask | (1 << i)] = mn[i][dp[mask]];
		p[mask | (1 << i)] = mask;
	}
	int mask = (1 << m) - 1;
	if (dp[mask] > n) {
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<vector<int>> ans(n);
	forn(_, m) {
		int i = __builtin_ctz(mask ^ p[mask]);
		for (int j = dp[p[mask]]; j < dp[mask]; ++j)
			ans[i].push_back(ord[j]);
		mask = p[mask];
	}
	forn(i, m) {
		printf("%d", int(ans[i].size()));
		for (int x : ans[i]) printf(" %d", x + 1);
		puts("");
	}
	return 0;
}