#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define M 7
#define INF (int)1e+9

int n, m;
vector<vector<int> >state[M];
map<vector<int>, int>rev[M];
vector<int>tmp;

void make_state(int cut, int k, bool pre, int nxt) {
	if (k == m) {
		rev[cut][tmp] = state[cut].size();
		state[cut].push_back(tmp);
		return;
	}
	tmp.push_back(0);
	make_state(cut, k + 1, false, nxt);
	tmp.pop_back();
	if (pre && (k != cut)) {
		tmp.push_back(tmp[k]);
		make_state(cut, k + 1, true, nxt);
		tmp.pop_back();
	}
	else {
		rep(i, nxt) {
			tmp.push_back(i + 1);
			make_state(cut, k + 1, true, max(nxt, i + 2));
			tmp.pop_back();
		}
	}
	return;
}

void renumbering(void) {
	int sz = tmp.size();
	int c[10], nxt = 1;
	rep(i, 10)c[i] = 0;
	rep(i, sz) {
		if (tmp[i] > 0) {
			if (c[tmp[i]] == 0)c[tmp[i]] = nxt, nxt++;
			tmp[i] = c[tmp[i]];
		}
	}
}

int judge(int k) {
	int sz = tmp.size();
	int cnt = 0, mx = 0;
	rep(i, sz) {
		mx = max(mx, tmp[i]);
		if (tmp[i] == tmp[k])cnt++;
	}
	if (cnt > 1)return 0;
	if (mx > 1)return -1;
	return 1;
}






int main() {

	vector<int>dp, dp2;
	int sz, x;
	int mx = 0;
	int cnt = 0;
	int ans = INF;

	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
		rep(j, m)if (s[i][j] == '#')mx = max(mx, i * m + j), cnt++;
	}

	tmp.push_back(0);
	rep(j, m)make_state(j, 0, false, 1);

	sz = state[0].size();
	rep(_, sz)dp.push_back(INF);

	dp[0] = 0;
	rep(i, n) {
		rep(j, m) {
			sz = state[(j + 1) % m].size();
			rep(_, sz)dp2.push_back(INF);
			sz = state[j].size();
			rep(idx, sz) {
				tmp = state[j][idx];
				if ((tmp[j] == 0) && (tmp[j + 1] == 0)) {
					if (s[i][j] == '.')dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx]);
					tmp[j + 1] = 9;
					renumbering();
					dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx] + 1);

				}
				else if ((tmp[j] == 0) && (tmp[j + 1] > 0)) {
					if (s[i][j] == '.') {
						x = judge(j + 1);
						if (x == 0) {
							tmp[j + 1] = 0;
							renumbering();
							dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx]);
						}
						if ((x == 1) && ((i * m + j) >= mx))ans = min(ans, dp[idx]);
					}
					tmp = state[j][idx];
					dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx] + 1);


				}
				else if ((tmp[j] > 0) && (tmp[j + 1] == 0)) {
					if (s[i][j] == '.')dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx]);
					tmp[j + 1] = tmp[j];
					dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx] + 1);
				}
				else if (tmp[j] == tmp[j + 1]) {
					if (s[i][j] == '.') {
						tmp[j + 1] = 0;
						dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx]);
					}
					tmp = state[j][idx];
					dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx] + 1);
				}
				else {
					if (s[i][j] == '.') {
						x = judge(j + 1);
						if (x == 0) {
							tmp[j + 1] = 0;
							renumbering();
							dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx]);
						}
						if ((x == 1) && ((i * m + j) >= mx))ans = min(ans, dp[idx]);
					}
					tmp = state[j][idx];
					x = tmp[j + 1];
					rep(ii, m + 1)if (tmp[ii] == x)tmp[ii] = tmp[j];
					renumbering();
					dp2[rev[(j + 1) % m][tmp]] = min(dp2[rev[(j + 1) % m][tmp]], dp[idx] + 1);
				}

			}
			dp = dp2;
			dp2.clear();
		}
	}

	sz = dp.size();
	rep(idx, sz) {
		x = 0;
		rep(j, m + 1)x = max(x, state[0][idx][j]);
		if (x <= 1) {
			ans = min(ans, dp[idx]);
		}
	}

	cout << (ans - cnt) << endl;
	return 0;
}
