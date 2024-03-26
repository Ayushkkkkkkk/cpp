#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void ternary() {
	ll a, b;
	cin >> a >> b;
	auto f = [&](ll n) -> double {
		return (double) a / sqrt(n + 1) + (double) b * n;
	};
	ll l = 0, r = a / b;
	while (r - l > 2) {
		ll m1 = (l * 2 + r) / 3;
		ll m2 = (l + r * 2) / 3;
		if (f(m1) > f(m2)) l = m1;
		else r = m2;
	}
	double ans = a;
	for (ll i = l; i <= r; i++) {
		ans = min(ans, f(i));
	}
	cout << fixed << setprecision(10) << ans << endl;
}