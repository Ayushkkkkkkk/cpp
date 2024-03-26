#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using point = pair<ll, ll>;

const int _N = 5e5 + 5;

int n;
ll a[_N], pre[_N], suf[_N], ans;
struct interval{
	int l, r; 
	ll d, dneed;
	int type, pos; // type0 - l, type1 - r
};
struct cmp{
	bool operator () (const interval &a, const interval &b) {
		return a.dneed - a.d > b.dneed - b.d;
	}
};

ll ceildiv(ll a, ll b) {
	// return a/b;
	if (a * b > 0) return a / b;
	else return a / b - !!(a % b);
}

namespace sg_left{ // [l, r] -> hull of point l-1 to r-1
	vector<int> hull[_N << 2];
	point pt[_N];
	void get_hull(int p, int l, int r) {
		int head = 0, tail = -1;
		for (int i = l; i <= r; i++) {
			while (head < tail && (pt[hull[p][tail]].second - pt[hull[p][tail - 1]].second) * (pt[i].first - pt[hull[p][tail]].first) <= (pt[i].second - pt[hull[p][tail]].second) * (pt[hull[p][tail]].first - pt[hull[p][tail - 1]].first)) {
				tail--;
				hull[p].pop_back();
			}
			tail++;
			hull[p].emplace_back(i);
		}
	}
	void build(int p, int l, int r) {
		get_hull(p, l - 1, r - 1);
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
	}
	pair<int, int> query(int p, int l, int r, int L, int R, point o) {
		if (l >= L && r <= R) { // do ternary search
			int tl = 1, tr = hull[p].size();
			while (tl < tr) {
				int m1 = (tl + tr) / 2, m2 = (tl + tr) / 2 + 1;
				auto p1 = pt[hull[p][m1 - 1]], p2 = pt[hull[p][m2 - 1]];
				if ((o.second - p1.second) * (o.first - p2.first) >= (o.second - p2.second) * (o.first - p1.first)) {
					tl = m1 + 1;
				} else tr = m2 - 1;
			}
			return {ceildiv((o.second - pt[hull[p][tl - 1]].second), (o.first - pt[hull[p][tl - 1]].first)), hull[p][tl - 1] + 1};
		}
		int mid = (l + r) >> 1;
		pair<int, int> res = {-1, -1};
		if (L <= mid) {
			res = query(p * 2, l, mid, L, R, o);
		} 
		if (R > mid) {
			auto res2 = query(p * 2 + 1, mid + 1, r, L, R, o);
			if (res == make_pair(-1, -1)) return res2;
			else {
				if (res2.first <= res.first) {
					return res2;
				} else return res;
			}
		}
		return res;
	}
	void test() {
		auto res = query(1, 1, n, 1, n, pt[n]);
		cout << res.first << ' ' << res.second << '\n';
	}
};
namespace sg_right{ // [l, r] -> hull of point l+1 to r+1
	vector<int> hull[_N << 2];
	point pt[_N];
	void get_hull(int p, int l, int r) {
		int head = 0, tail = -1;
		for (int i = l; i <= r; i++) {
			while (head < tail && (pt[hull[p][tail]].second - pt[hull[p][tail - 1]].second) * (pt[i].first - pt[hull[p][tail]].first) < (pt[i].second - pt[hull[p][tail]].second) * (pt[hull[p][tail]].first - pt[hull[p][tail - 1]].first)) {
				tail--;
				hull[p].pop_back();
			}
			tail++;
			hull[p].emplace_back(i);
		}
	}
	void build(int p, int l, int r) {
		get_hull(p, l + 1, r + 1);
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
	}
	pair<int, int> query(int p, int l, int r, int L, int R, point o) {
		if (l >= L && r <= R) { // do ternary search
			int tl = 1, tr = hull[p].size();
			while (tl < tr) {
				int m1 = (tl + tr) / 2, m2 = (tl + tr) / 2 + 1;
				auto p1 = pt[hull[p][m1 - 1]], p2 = pt[hull[p][m2 - 1]];
				if ((o.second - p1.second) * (o.first - p2.first) <= (o.second - p2.second) * (o.first - p1.first)) {
					tl = m1 + 1;
				} else tr = m2 - 1;
			}
			return {ceildiv(-(o.second - pt[hull[p][tl - 1]].second), (o.first - pt[hull[p][tl - 1]].first)), hull[p][tl - 1] - 1};
		}
		int mid = (l + r) >> 1;
		pair<int, int> res = {-1, -1};
		if (L <= mid) {
			res = query(p * 2, l, mid, L, R, o);
		} 
		if (R > mid) {
			auto res2 = query(p * 2 + 1, mid + 1, r, L, R, o);
			if (res == make_pair(-1, -1)) return res2;
			else {
				if (res.first <= res2.first) {
					return res;
				} else return res2;
			}
		}
		return res;
	}
	void test() {
		auto res = query(1, 1, n, 1, n, pt[1]);
		cout << res.first << ' ' << res.second << '\n';
	}
};


int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << max(a[1] + 1, 0ll) << '\n';
		return 0;
	}
	sg_left::pt[0] = {0, 0}; sg_right::pt[n + 1] = {n + 1, 0};
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		sg_left::pt[i] = {i, pre[i]};
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
		sg_right::pt[i] = {i, suf[i]};
	}
	sg_left::build(1, 1, n);
	sg_right::build(1, 1, n);
	ll ans = 0;
	priority_queue<interval, vector<interval>, cmp> q;
	pair<int, int> resL = sg_left::query(1, 1, n, 1, n, sg_left::pt[n]);
	pair<int, int> resR = sg_right::query(1, 1, n, 1, n, sg_right::pt[1]);
	if (resL.second == 1) q.push({1, n, 0, resR.first + 1, 1, resR.second});
	else if (resR.second == n) q.push({1, n, 0, resL.first + 1, 0, resL.second});
	else if (resL.first <= resR.first) q.push({1, n, 0, resL.first + 1, 0, resL.second});
	else q.push({1, n, 0, resR.first + 1, 1, resR.second});
	while (!q.empty()) {
		auto x = q.top(); q.pop();
		if (x.d < x.dneed) {
			ans += x.dneed - x.d;
			x.d = x.dneed;
		}
		//split
		if (x.type == 1) x.pos++;
		int l = x.l, r = x.r;
		resL = sg_left::query(1, 1, n, l, x.pos - 1, sg_left::pt[x.pos - 1]);
		resR = sg_right::query(1, 1, n, l, x.pos - 1, sg_right::pt[l]);
		if (l == x.pos - 1) {
			ans += max(0ll, a[l] - x.d + 1);
		} else {
			if (resL.second == l) q.push({l, x.pos - 1, x.d, resR.first + 1, 1, resR.second});
			else if (resR.second == r) q.push({l, x.pos - 1, x.d, resL.first + 1, 0, resL.second});
			else if (resL.first <= resR.first) q.push({l, x.pos - 1, x.d, resL.first + 1, 0, resL.second});
			else q.push({l, x.pos - 1, x.d, resR.first + 1, 1, resR.second});
		}
		resL = sg_left::query(1, 1, n, x.pos, r, sg_left::pt[r]);
		resR = sg_right::query(1, 1, n, x.pos, r, sg_right::pt[x.pos]);
		if (x.pos == r) {
			ans += max(0ll, a[r] - x.d + 1);
		} else {
			if (resL.second == l) q.push({x.pos, r, x.d, resR.first + 1, 1, resR.second});
			else if (resR.second == r)q.push({x.pos, r, x.d, resL.first + 1, 0, resL.second});
			else if (resL.first < resR.first) q.push({x.pos, r, x.d, resL.first + 1, 0, resL.second});
			else q.push({x.pos, r, x.d, resR.first + 1, 1, resR.second});
		}
	}
	cout << ans << '\n';
}