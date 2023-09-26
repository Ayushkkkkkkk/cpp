#include <bits/stdc++.h>
using namespace std;
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
using ll = int64_t;
void solve(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(ll& x : A) cin >> x;
	vector<vector<int> > tree(N);
	for(int i = 0; i < N-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	vector<ll> ans(N);
	vector<ll> ssz(N);
	vector<int> par(N);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			ssz[v] = 1;
			par[v] = p;
			for(int w : tree[v]){
				if(w == p) continue;
				self(w, v);
				ssz[v] += ssz[w];
			}
		}
	)(0, -1);
	ll root_ans = 0;
	for(int v = 1; v < N; v++){
		root_ans += ssz[v] * (A[v] ^ A[par[v]]);
	}
	y_combinator(
		[&](auto self, int v, int p, ll cur_ans) -> void {
			ans[v] = cur_ans;
			for(int w : tree[v]){
				if(w == p) continue;
				ll new_ans = cur_ans + (N - ssz[w] - ssz[w]) * (A[v] ^ A[w]);
				self(w, v, new_ans);
			}
		}
	)(0, -1, root_ans);
	for(int i = 0; i < N; i++){
		cout << ans[i] << " \n"[i == N-1];
	}
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}