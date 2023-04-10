#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
#define ll long long

template<typename Node>
struct SparseTable {
	vector<vector<Node>> table;
	vector<ll> logValues;
	int n;
	int maxLog;
	vector<ll> a;
	SparseTable(int n1, vector<ll> &arr) {
		n = n1;
		a = arr;
		table.resize(n);
		logValues.resize(n + 1);
		maxLog = log2(n);
		logValues[1] = 0;
		for (int i = 2; i <= n; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
		for (int i = 0; i < n; i++) {
			table[i].resize(maxLog + 1);
			fill(all(table[i]), Node());
		}
		build();
	}
	void build() {
		for (int i = 0; i < n; i++) {
			table[i][0] = Node(a[i]);
		}
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; (j + (1 << i)) <= n; j++) {
				table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	Node queryNormal(int left, int right) {
		Node ans = Node();
		for (int j = logValues[right - left + 1]; j >= 0; j--) {
			if ((1 << j) <= right - left + 1) {
				ans.merge(ans, table[left][j]);
				left += (1 << j);
			}
		}
		return ans;
	}
	Node queryIdempotent(int left, int right) {
		int j = logValues[right - left + 1];
		Node ans = Node();
		ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
		return ans;
	}
};
struct Node1 {
	ll val; 
	Node1() { 
		val = 0;
	}
	Node1(ll v) {
		val = v;
	}
	void merge(Node1 &l, Node1 &r) {
		val = l.val ^ r.val;
	}
};

const int N = 1e3 + 10;
 vector<vector<int>> pref(N + 1 , vector<int>(N + 1 , 0));
int main(){
    int n , m ; cin >> n , m ;
    vector<vector<int>> a(n , vector<int>(m , 0));
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j<=m ; j++){
            cin >> a[i][j];
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    int q ; cin >> q;
   while(q--){
    ll a , b , c , d;
    cin >> a >> b >> c >> d;
    cout << pref[c][d] - pref[a - 1][d] - pref[c][b-1] + pref[a - 1][b - 1];
   }

}