// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	// DFS
// 	void findTopoSort(vector<int> adj[], vector<bool> &visited, stack<int> &st, int s){
// 	    visited[s]=true;
// 	    for(int i:adj[s]){
// 	        if(visited[i]==false)
// 	           findTopoSort(adj,visited, st, i);
// 	    }
// 	    st.push(s);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]){
// 	    // code here
// 	    stack<int> st;
// 	    vector<bool> visited(V,false);
// 	    for(int i=0;i<V;i++){
// 	        if(visited[i]==0)
// 	            findTopoSort(adj, visited, st, i);
// 	    }
// 	    vector<int> topo;
// 	    while(!st.empty()){
// 	        topo.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return topo;
// 	}
	
	
	//BFS
	vector<int> topoSort(int V, vector<int> adj[]){
	    queue<int> q; 
	    vector<int> indegree(V, 0); 
	    for(int i = 0;i<V;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    for(int i = 0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends