#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 8;

int n, K, a[N], pre[N * 2];
long long dp[N * 2], ans;

vector<int> trim(vector<int> a, int L, int R) {
	return vector(a.begin() + L, a.end() - R);
}
vector<int> init() {
	static int q[N];
	q[1] = 0;
	for (int i = 1, l = 1, r = 1; i <= n; i++) {
		if (q[l] < i - K) l++;
		dp[i] = dp[q[l]] + a[i], pre[i] = q[l];
		while (l <= r && dp[i] < dp[q[r]]) r--;
		q[++r] = i;
	}
	ans = dp[n];
	vector<int> res;
	for (int i = n; i; i = pre[i]) res.push_back(i);
	res.push_back(0), reverse(res.begin(), res.end());
	return res;
}
vector<int> solve(int first, vector<int> L, vector<int> R) {
	dp[first] = a[first];
	int l = first, r = first;
	long long val; int p;
	auto checkMin = [&](int i) {
		if (dp[i] < val) val = dp[i], p = i;
	};
	for (int i = 0; i < L.size(); i++) {
		val = 1e18, p = 0;
		for (int j = R[i]; j >= L[i]; j--) {
			for (; r >= max(l, j - K); r--) checkMin(r + i);
			dp[j + i + 1] = val + a[j];
			pre[j + i + 1] = p;
		}
		l = L[i], r = R[i];
	}
	val = 1e18, p = 0;
	for (int i = max(L.back(), n - K + first); i <= R.back(); i++)
		checkMin(i + L.size());
	ans = min(ans, val);
	vector<int> res;
	for (int i = L.size(); i; i--) res.push_back(p - i), p = pre[p];
	reverse(res.begin(), res.end());
	return res;
}
void divide(int l, int r, vector<int> L, vector<int> R) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	auto M = solve(mid, L, R);
	divide(l, mid - 1, L, M), divide(mid + 1, r, M, R);
}
void divide(vector<int> p) {
	p.push_back(n), divide(1, p[0], trim(p, 0, 1), trim(p, 1, 0));
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> K;
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[0] = a[n];
		auto p = init();
		divide(trim(p, 1, 1));
		divide(solve(0, trim(p, 0, 1), trim(p, 1, 0)));
		if ((p.size() - 2) * K >= n)
			divide(solve(0, trim(p, 1, 2), trim(p, 2, 1)));
		cout << ans << '\n';
	}
}