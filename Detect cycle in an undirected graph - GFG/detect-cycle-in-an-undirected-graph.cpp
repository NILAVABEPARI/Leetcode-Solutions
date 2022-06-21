// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // using dfs
//     bool DFSRec(vector<int> adj[], vector<bool> &visited, int source, int parent){
// 	    visited[source]=true;
// 	    for(auto i:adj[source]){
// 	        if(visited[i]==false){
// 	             if(DFSRec(adj, visited, i, source)==true)
// 	                return true;
// 	        }
// 	        else if(i!=parent)
// 	            return true;
// 	    }
// 	    return false;
// 	}
// 	bool isCycle(int V, vector<int>adj[]){
// 	    // Code here
// 	    vector<bool> visited(V,false);
// 	    for(int i=0;i<V;i++){
// 	        if(visited[i]==false){
// 	            if(DFSRec(adj, visited, i, -1)==true)
// 	                return true;
// 	        }
// 	    }
// 	    return false;
// 	}



    // using bfs
	bool checkForCycle(int s, vector<int> adj[], vector<int> &visited){
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : adj[node]){
                if (!visited[it]){
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (checkForCycle(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends