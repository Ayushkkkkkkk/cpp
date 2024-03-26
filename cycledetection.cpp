#include<bits/stdc++.h>

using namespace std;

class Solution {

  public:
    bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false;
    }
  public:
    bool isCycle(int V, vector < int > adj[]) {
      vector < int > vis(V + 1, 0);
      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          if (checkForCycle(i, -1, vis, adj)) return true;
        }
      }

      return false;
    }
};

// { Driver Code Starts.
int main() {

  int V ;
  int E ;
  cin >> V >> E;
  vector < int > adj[V];
	
  for (int i = 0 ; i < E ; i++){
  	int x , y ; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans) {
    cout << "NO" << endl;;
  } else cout << "YES"<< endl;

  return 0;
}