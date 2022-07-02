// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfsRec(int &cnt, int node, int dest, vector<bool>&vis, vector<vector<int>>graph){
        if(node==dest){
            cnt++;
            return;
        }
        vis[node]=true;
        for(auto it:graph[node]){
            if(!vis[it])
                dfsRec(cnt,it,dest,vis,graph);
        }
        vis[node]=false;
        return ;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>>graph(n);
	    vector<bool>vis(n,false);
	    int cnt=0;
	    for(int i=0;i<edges.size();i++)
	        graph[edges[i][0]].push_back(edges[i][1]);
        dfsRec(cnt,s,d,vis,graph);
        return cnt;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends