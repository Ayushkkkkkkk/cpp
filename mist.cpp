#include <iostream>
#include <string>
#include <set>
#include <cstring>
#define int long long

using namespace std;

const int L = 26;
const int MAXN = 200200;

int n, m;
string s;
set<int> M2, M3;
int fen[MAXN];

void fenadd(int i, int x) {
	x = (x % L + L) % L;
	for (; i < n; i |= (i + 1))
		fen[i] = (fen[i] + x) % L;
}

int fenget(int i) {
	int ans = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ans = (ans + fen[i]) % L;
	return ans;
}

void relax(int l, int r) {
	l = max(l, 0LL);
	r = min(r, n);
	for (int i = l; i + 1 < r; ++i) {
		int c1 = fenget(i);
		int c2 = fenget(i + 1);

		if (c1 == c2) M2.insert(i);
		else M2.erase(i);

		if (i + 2 >= r) continue;

		int c3 = fenget(i + 2);
		if (c1 == c3) M3.insert(i);
		else M3.erase(i);
	}
}

void build() {
	M2.clear();
	M3.clear();
	memset(fen, 0, n * sizeof(int));
	fenadd(0, s[0] - 'a');
	for (int i = 1; i < n; ++i) {
		fenadd(i, s[i] - s[i - 1] + L);
	}
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == s[i + 1]) M2.insert(i);
		if (i + 2 < n && s[i] == s[i + 2]) M3.insert(i);
	}
}

void update(int l, int r, int x) {
	fenadd(l, x);
	relax(l - 5, l + 5);
	fenadd(r, L - x);
	relax(r - 5, r + 5);
}

bool query(int l, int r) {
	auto it = M2.lower_bound(l);
	if (it != M2.end() && *it + 1 < r) return false;
	it = M3.lower_bound(l);
	if (it != M3.end() && *it + 2 < r) return false;
	return true;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		build();
		while (m--) {
			int tp, l, r; cin >> tp >> l >> r, --l;
			if (tp == 1) {
				int x; cin >> x;
				update(l, r, x);
			} else {
				cout << (query(l, r) ? "YES" : "NO") << '\n';
			}
		}
	}
}