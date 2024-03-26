//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define mp make_pair
#define all(x) (x).begin(),(x).end()

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll floor_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x >= 0) return x / y;
	return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x <= 0) return x / y;
	return (x - 1) / y + 1;
}

const int N = 1010;
map<int, int> forX[N];
vector<int> g[2 * N];
int n;
int par[2 * N];
int h[2 * N];

int getColor(int x, int y) {
	if (forX[x].count(y)) return forX[x][y];
	printf("? %d %d\n", x + 1, y + 1);
	fflush(stdout);
	int c;
	scanf("%d", &c);
	forX[x][y] = c;
	return c;
}

void dfs(int v) {
	for (int u : g[v]) if (h[u] == -1) {
		h[u] = h[v] + 1;
		par[u] = v;
		dfs(u);
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		forX[i].clear();
	}
	for (int i = 0; i < 2 * n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < 2 * n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		g[x].push_back(n + y);
		g[n + y].push_back(x);
		forX[x][y] = i + 1;
	}
	for (int i = 0; i < 2 * n; i++) {
		par[i] = -1;
		h[i] = -1;
	}
	for (int i = 0; i < 2 * n; i++) if (h[i] == -1) {
		h[i] = 0;
		dfs(i);
	}
	for (int v = 0; v < 2 * n; v++) {
		eprintf("%d: %d %d\n", v, h[v], par[v]);
	}
	vector<int> cyc;
	for (int v = 0; cyc.empty() && v < 2 * n; v++) {
		for (int e : g[v]) {
			int u = e;
			if (h[u] <= h[v] + 1) continue;
			while(u != v) {
				cyc.push_back(u);
				u = par[u];
			}
			cyc.push_back(u);
			break;
		}
	}
	eprintf("cyc: ");
	for (int x : cyc)
		eprintf("%d ", x);
	eprintf("\n");
	assert((int)cyc.size() >= 4 && (int)cyc.size() % 2 == 0);
	if (cyc[0] >= n) reverse(all(cyc));
	while((int)cyc.size() > 4) {
		int p = (int)cyc.size() / 2;
		if (p % 2 == 0) p++;
		assert(cyc[p] >= n);
		int c = getColor(cyc[0], cyc[p] - n);
		bool ok = true;
		for (int i = 0; i < p; i++) {
			int cur;
			if (i % 2 == 0)
				cur = getColor(cyc[i], cyc[i + 1] - n);
			else
				cur = getColor(cyc[i + 1], cyc[i] - n);
			ok &= cur != c;
		}
		if (ok) {
			p++;
			while((int)cyc.size() > p) cyc.pop_back();
		} else {
			vector<int> nw;
			nw.push_back(cyc[0]);
			for (int i = p; i < (int)cyc.size(); i++)
				nw.push_back(cyc[i]);
			cyc = nw;
		}
	}
	printf("! %d %d %d %d\n", 1 + cyc[0], 1 + cyc[2], 1 + cyc[1] - n, 1 + cyc[3] - n);
	fflush(stdout);
	string s;
	cin >> s;
	if (s != "OK") exit(0);
}

int main() {
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		eprintf("--- Case #%d start ---\n", i);
		//printf("Case #%d: ", i);

		solve();

		//printf("%lld\n", (ll)solve());

		/*
		if (solve()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		*/

		eprintf("--- Case #%d end ---\n", i);
		eprintf("time = %.5lf\n", getCurrentTime());
		eprintf("++++++++++++++++++++\n");
	}


	return 0;
}
