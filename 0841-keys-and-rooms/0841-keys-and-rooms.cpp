class Solution {
public:
    void dfs(int node, vector<bool>&vis, vector<vector<int>>& rooms){
        vis[node]=true;
        for(auto &it:rooms[node]){
            if(!vis[it])
                dfs(it,vis,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(0,vis,rooms);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};