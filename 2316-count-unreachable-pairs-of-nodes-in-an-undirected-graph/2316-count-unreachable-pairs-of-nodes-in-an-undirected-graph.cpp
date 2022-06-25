class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>>& g, vector<bool>&vis, int i){
        vis[i]=true;
        cnt++;
        for(auto it:g[i]){
            if(!vis[it])                
                dfs(g,vis,it);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //make graph
        vector<vector<int>>g(n);
        for(auto &it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }        
        vector<bool>vis(n,false);
        vector<int>temp;
        int prev=0,rem=n;
        for (int i = 0; i < n; i++) {
            if (!vis[i]){
                cnt=0;
                dfs(g,vis,i);
                temp.push_back(cnt);
            }
        }
        long long ln=temp.size(),presum=0,ans=0;
        for(long long i=0;i<temp.size();i++){
            ans+=presum*temp[i];            
            presum+=temp[i];
        }
        return ans;
    }
};