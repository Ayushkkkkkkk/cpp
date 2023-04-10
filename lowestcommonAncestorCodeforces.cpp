#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v) {for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v) {for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v) {for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v) {for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T, U>& operator--           (pair<T, U> &p) {--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T, U>& operator++           (pair<T, U> &p) {++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p) {is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {return mp(a.first - b.first, a.second - b.second);}
template<typename T, typename U> pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {return mp(a.first + b.first, a.second + b.second);}
template<typename T, typename U> void umin(T& a, U b) {if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b) {if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;

    vector<vector<pair<int, int>>> up(n, vector<pair<int, int>>(m, { -1, -1}));
    vector<vector<pair<int, int>>> down(n, vector<pair<int, int>>(m, {n, n}));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != 0) up[i][j] = up[i - 1][j];
            if (v[i][j] == '#') {
                up[i][j] = {i, i};
            } else if (v[i][j] == 'm') {
                swap(up[i][j].first, up[i][j].second);
                up[i][j].first = i;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (i != n - 1) down[i][j] = down[i + 1][j];
            if (v[i][j] == '#') {
                down[i][j] = {i, i};
            } else if (v[i][j] == 'm') {
                swap(down[i][j].first, down[i][j].second);
                down[i][j].first = i;
            }
        }
    }

    int ans = 0;
    for (int r = 1; r + 1 < n; ++r) {
        for (int c1 = 0; c1 < m; ++c1) {
            int med = 0;
            for (int c2 = c1; c2 < m; ++c2) {
                if (v[r][c2] == '#') {
                    break;
                } else if (v[r][c2] == 'm') {
                    ++med;
                    if (med > 1) break;
                }
                if (c2 <= c1 + 1) continue;
                auto up1 = up[r - 1][c1]; up1.first = r - up1.first; up1.second = r - up1.second;
                auto up2 = up[r - 1][c2]; up2.first = r - up2.first; up2.second = r - up2.second;
                auto down1 = down[r + 1][c1]; down1.first -= r; down1.second -= r;
                auto down2 = down[r + 1][c2]; down2.first -= r; down2.second -= r;

                auto upd = [&](int up, int down) {
                    up -= 1;
                    down -= 1;
                    if (up == 0 || down == 0) return;
                    ans = max(ans, up * 2 + down * 2 + c2 - c1 + 1);
                };

                if (med == 0) {
                    upd(min(up1.second, up2.first), min(down1.first, down2.first));
                    upd(min(up1.first, up2.second), min(down1.first, down2.first));
                    upd(min(up1.first, up2.first), min(down1.second, down2.first));
                    upd(min(up1.first, up2.first), min(down1.first, down2.second));
                } else {
                    upd(min(up1.first, up2.first), min(down1.first, down2.first));
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}