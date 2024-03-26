#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int &i: d) cin >> i;
    vector<int> l(2), c(2), k(2);
    for (int i = 0; i < 2; i++) {
        cin >> l[i] >> c[i] >> k[i];
    }
    vector dp(n + 1, vector<int>(k[0] + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k[0]; j++) {
            int rem = d[i];
            for (int nj = j; nj <= k[0]; nj++) {
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + (rem + l[1] - 1) / l[1]);
                rem = max(rem - l[0], 0);
            }
        }
    }
    ll ans = 2e18;
    for (int i = 0; i <= k[0]; i++) {
        if (dp[n][i] > k[1]) continue;
        ans = min(ans, (ll) c[0] * i + (ll) c[1] * dp[n][i]);
    }
    if (ans > 1e18) ans = -1;
    cout << ans << endl;
}
