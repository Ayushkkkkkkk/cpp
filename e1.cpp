#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	vector<int> sz(2);
	for(int x = 0; x < 2; x++) cin >> sz[x];
	vector<vector<int> > perms(2);
	for(int x = 0; x < 2; x++){
		vector<int> perm(sz[x]);
		for(int& y : perm) cin >> y;
		perm.insert(perm.begin(), 0);
		perms[x] = perm;
	}
	vector<vector<int> > parity_best(2, {-1});
	int best_score = 1e9;
	for(int parity = 0; parity < 2; parity++){
		vector<vector<int> > best(2, {-1});
		for(int x = 0; x < 2; x++){
			int N = (int)perms[x].size();
			vector<int> goal(N);
			for(int i = 0; i < N; i++) goal[i] = i;
			for(int z = 0; z < N; z++){
				vector<int> loc(N, 0);
				vector<int> cur = perms[x];
				for(int i = 0; i < N; i++) loc[cur[i]] = i;
 
				vector<int> ops;
				auto sw = [&](int a, int b) -> void {
					assert(a == loc[0]);
					ops.push_back((b-a+N) % N);
					swap(loc[cur[a]], loc[cur[b]]);
					swap(cur[a], cur[b]);
				};
 
				while(goal[loc[0]] != 0){
					int a = loc[0];
					int b = loc[goal[a]];
					sw(a, b);
				}
				int ct = 0;
				while(ct < N){
					if(cur[ct] == goal[ct]){
						ct++;
						continue;
					}
					if(ct != loc[0]) {
						sw(loc[0], ct);
					}
					while(goal[loc[0]] != 0){
						int a = loc[0];
						int b = loc[goal[a]];
						sw(a, b);
					}
				}
				if((int)ops.size() % 2 == parity){
					if(best[x] == vector<int>{-1} || ops.size() < best[x].size()) best[x] = ops;
				}
 
				rotate(goal.begin(), goal.begin() + 1, goal.end());
			}
		}
		if(best[0] == vector<int>{-1}) continue;
		if(best[1] == vector<int>{-1}) continue;
		for(int x : {0, 1}){
			while(best[x].size() < best[x^1].size()){
				int N = (int)perms[x].size();
				best[x].push_back(1);
				best[x].push_back(N-1);
			}
		}
		int score = (int)max(best[0].size(), best[1].size());
		if(score < best_score){
			best_score = score;
			parity_best = best;
		}
	}
	if(best_score >= int(1e9)){
		cout << -1 << '\n';
	} else {
		cout << parity_best[0].size() << '\n';
		for(int i = 0; i < parity_best[0].size(); i++){
			cout << parity_best[0][i] << ' ' << parity_best[1][i] << '\n';
		}
	}
}
