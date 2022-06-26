class Solution {
public:
    void dfsRec(int node, vector<bool>&vis, vector<vector<int>>& graph,
                vector<int>&temp, vector<vector<int>>&ans){
        vis[node]=true;
        temp.push_back(node);
        if(node==graph.size()-1) ans.push_back(temp);
        for(auto &it:graph[node]){
            if(!vis[it])
                dfsRec(it,vis,graph,temp,ans);
        }
        temp.pop_back();
        vis[node]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        vector<int>temp;
        dfsRec(0,vis,graph,temp,ans);        
        return ans;
    }
};