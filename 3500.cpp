#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<assert.h>
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>void read(T&x) {
	static char c; static int f;
	for (c = ch(), f = 1; c < '0' || c > '9'; c = ch())if (c == '-')f = -f;
	for (x = 0; c >= '0' && c <= '9'; c = ch())x = x * 10 + (c & 15); x *= f;
}
template<typename T>void write(T x) {
	static char q[65]; int cnt = 0;
	if (x < 0)pc('-'), x = -x;
	q[++cnt] = x % 10, x /= 10;
	while (x)
		q[++cnt] = x % 10, x /= 10;
	while (cnt)pc(q[cnt--] + '0');
}
const int maxn = 20000005;
struct Count {
	int pos, val;
	Count(int pos = -1, int val = -1):
		pos(pos), val(val) {}
};
int plus(int x, int y) {
	return (x < 0 || y < 0) ? -1 : x + y;
}
Count operator + (const Count A, const Count B) {
	int Ap = A.pos, Bp = B.pos, va = plus(A.val, B.val);
	if (~Ap && ~Bp)return Ap ^ Bp ? Count() : Count(Ap | Bp, va);
	if (~Ap || ~Bp)return Count(Ap & Bp, va);
	return Count(-1, va);
}
Count operator * (const Count A, const Count B) {
	int Ap = A.pos, Bp = B.pos, va = plus(A.val, B.val);
	if (~Ap && ~Bp)return Count(Ap ^ Bp, va);
	if (~Ap || ~Bp)return Count(-1, va);
	return Count(-1, plus(va, 1));
}
int c[maxn];
int tn, Op[maxn], Cn[maxn];
Count dp[maxn];
int t, hb[maxn], rev[maxn];
void pushup(int p) {
	int l = p << 1, r = l | 1;
	dp[p] = ((t & hb[p]) ? (dp[l] + dp[r]) : (dp[l] * dp[r]));
}
int va1, sum;
void ins(int i) {
	int p = rev[(i & (tn - 1))];
	if (~c[i])Op[p] ^= c[i]; else ++Cn[p];
	if (dp[p + tn].pos > 0)--va1; else sum -= dp[p + tn].val;
	dp[p + tn] = (Cn[p] ? Count(-1, Cn[p] - 1) : Count(Op[p], 0));
	if (dp[p + tn].pos > 0)++va1; else sum += dp[p + tn].val;
}
void del(int i) {
	int p = rev[(i & (tn - 1))];
	if (~c[i])Op[p] ^= c[i]; else --Cn[p];
}
int power(int a, int x, int p) {
	if (x == -1)return 0;
	int re = 1;
	while (x) {
		if (x & 1)re = 1ll * re * a % p;
		a = 1ll * a * a % p; x >>= 1;
	}
	return re;
}
int main() {
	int n, m, w;
	read(n), read(m), read(t), read(w);
	memset(c, -1, sizeof c);
	for (int i = 1; i <= m; ++i) {
		int d; read(d); --d; read(c[d]);
	}
	tn = (n & (-n));
	hb[0] = 0; hb[1] = 1;
	for (int i = 2; i < tn * 2; ++i)
		hb[i] = (hb[i >> 1] << 1);
	int cn = -1; for (; (1 << (cn + 1)) < tn; ++cn);
	for (int i = 1; i < tn; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << cn);
	for (int i = 0; i < tn; ++i)dp[i + tn].val = 0;
	for (int i = 0; i < n; ++i)ins(i);
	if (t < tn)for (int i = tn - 1; i >= 1; --i)pushup(i);
	int q; read(q);
	while (q--) {
		int f; read(f); --f;
		del(f); read(c[f]); ins(f);
		int p; read(p);
		if (t >= tn) {
			write(va1 ? 0 : power((1 << w) % p, sum, p));
		}
		else {
			int now = (rev[(f & (tn - 1))] | tn); while (now >>= 1)pushup(now);
			write(power((1 << w) % p, plus(dp[1].val, dp[1].pos == -1), p));
		}
		pc('\n');
	}
	return 0;
}