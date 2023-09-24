#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 15;

void rec(int ns, int last, vector<int>& now, vector<vector<int>>& aint, vector<int>& col, vector<int>& sz, int& ss, int sns) {
    if (ss < 0) {
        return;
    }
	if (ns == 0) {
		col.back()++;
		aint.push_back(now);
		ss -= sns;
		return;
	}
	for (int i = min(last, col[ns] - 1); i >= 0; i--) {
		now.push_back(i);
		rec(ns - sz[i], i, now, aint, col, sz, ss, sns);
		now.pop_back();
	}
}

void dfs(int v, int p, vector<vector<int>>& arr, vector<int>& num, map<vector<int>, int>& m, vector<int>& sz) {
	vector<int> now;
	sz[v] = 1;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, num, m, sz);
			sz[v] += sz[i];
			if (sz[v] <= MAXSZ) {
			    now.push_back(num[i]);
			}
		}
	}
	if (sz[v] > MAXSZ) {
		num[v] = -1;
		return;
	}
	stable_sort(now.begin(), now.end());
	reverse(now.begin(), now.end());
	num[v] = m[now] - 1;
}

void dfs2(int x, int p, vector<vector<int>>& aint, vector<int>& ans) {
	if (p >= 0) {
		ans.push_back(p);
	}
	int now = ans.size();
	for (auto i : aint[x]) {
		dfs2(i, now, aint, ans);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> aint(1);
	vector<vector<int>> arr(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	map<vector<int>, int> m;
	vector<int> col(1, 0), sz(1, 1);
	col.push_back(1);
	for (int i = 2; i <= MAXSZ; i++) {
		vector<int> now;
		col.push_back(col.back());
		int ss = n;
		rec(i - 1, aint.size() - 1, now, aint, col, sz, ss, i);
		while (sz.size() < col.back()) {
			sz.push_back(i);
		}
		if (ss < 0) {
		    break;
		}
	}
	for (int i = 0; i < col.back(); i++) {
		m[aint[i]] = i + 1;
	}
	vector<int> num(n), szi(n, 1);
	dfs(0, 0, arr, num, m, szi);
	set<int> s;
	for (int i = 0; i < col.back(); i++) {
		s.insert(i);
	}
	for (auto i : num) {
		s.erase(i);
	}
	int x = *s.begin();
	vector<int> ans;
	if (sz[x] > n) {
		for (int i = 0; i < n; i++) {
			for (auto j : arr[i]) {
				if (i < j) {
					cout << i + 1 << ' ' << j + 1 << '\n';
				}
			}
		}
		return;
	}
	for (int i = 0; i < n - sz[x] - 1; i++) {
		ans.push_back(i);
	}
	dfs2(x, n - sz[x] - 1, aint, ans);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << ' ' << i + 2 << '\n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}