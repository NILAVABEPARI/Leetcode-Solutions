class Solution {
public:
    void dfs(int node, vector<bool>&vis, vector<vector<int>>& graph){
        vis[node]=true;
        for(auto &it:graph[node]){
            if(!vis[it])
                dfs(it,vis,graph);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<bool>vis(n,false);
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && isConnected[i][j])
                    graph[i].push_back(j);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<"->";
        //     for(int j=0;j<graph[i].size();j++)
        //         cout<<graph[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
                cnt++;
            }
        }
        return cnt;
    }
};