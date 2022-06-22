// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(vector<int>adj[],int v,stack<int>&st,vector<int>&vis){
        vis[v]=1;
        for(auto it:adj[v]){
            if(vis[it]==0)
                dfs(adj,it,st,vis);
        }
        st.push(v);
    }
    
    void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
        vis[node] = 1; 
        for(auto it: transpose[node]) {
            if(!vis[it]) {
                revDfs(it, vis, transpose); 
            }
        }
    }

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]){
        //code here
        stack<int> st;
    	vector<int> vis(V+1, 0); 
    	for(int i=0;i<V;i++) {
    	    if(!vis[i]) {
    	        dfs(adj,i,st,vis);
    	    }
    	}
    	
    	vector<int> transpose[V];
    	for(int i=0;i<V;i++) {
    	    vis[i] = 0; 
    	    for(auto it: adj[i]) {
    	        transpose[it].push_back(i); 
    	    }
    	}
    	
    	//int vi[V]={0};
        int ans=0;
    	while(!st.empty()) {
    	    int node = st.top();
    	    st.pop(); 
    	    if(!vis[node]) {
    	        ans++;
    	        revDfs(node, vis, transpose);
    	    }
	    }
	    return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends