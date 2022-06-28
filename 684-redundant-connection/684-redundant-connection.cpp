class Solution {
public:
    bool dfs(int node, int par, vector<bool>&vis, vector<vector<int>>&graph){
        if(vis[node]) return true;
        vis[node]=true;
        for(auto &it:graph[node]){
            // if(!vis[it] && dfs(it,node,vis,graph)) return true;
            // else if(it!=par) return true;
            if(it!=par && dfs(it,node,vis,graph)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>graph(n+1);
            vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++){
            fill(begin(vis), end(vis), false);
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            if(dfs(edges[i][0],-1,vis,graph)) return edges[i];
        }        
        return {};
    }
};