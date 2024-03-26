#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define rev(i, n, init) for (int i = (int)n; i >= init; i--)
#define V vector<int>
#define VV vector<V>
#define Vll vector<ll>
#define VVll vector<Vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Vpii vector<pii>
#define VVpii vector<Vpii>
#define Vpll vector<pll>
#define VVpll vector<Vpll>

int n, m;
bool check(int mid, VV a)
{
    VV pre(n + 1, V(m + 1));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (a[i][j] >= mid) a[i][j] = 1;
            else a[i][j] = 0;
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + a[i][j];
        }
    }
    rep(i, mid, n + 1)
    {
        rep(j, mid, m + 1)
        {
            int sum = pre[i][j] - pre[i][j - mid] - pre[i - mid][j] + pre[i - mid][j - mid];
            if (sum == mid * mid) return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    VV a(n, V(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    int l = 0, r = min(n, m), ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, a))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
int main() {
    fastio();
    // freopen("output.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = 1;
    cin >> tt;
    rep(ii, 1, tt + 1)
    {
        solve();
    }
    return 0;
}