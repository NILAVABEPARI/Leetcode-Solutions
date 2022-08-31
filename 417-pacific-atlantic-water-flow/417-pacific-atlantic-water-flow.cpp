class Solution {
public:
    vector<vector<bool>>atlantic, pacific;
    vector<vector<int>>ans;
    int n,m;
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&heights, int par){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || heights[i][j]<par) return;
        vis[i][j]=true;
        dfs(i+1,j,vis,heights,heights[i][j]);
        dfs(i,j+1,vis,heights,heights[i][j]);
        dfs(i-1,j,vis,heights,heights[i][j]);
        dfs(i,j-1,vis,heights,heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        atlantic = pacific = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(i,0,pacific,heights,INT_MIN);
            dfs(i,m-1,atlantic,heights,INT_MIN);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,pacific,heights,INT_MIN);
            dfs(n-1,j,atlantic,heights,INT_MIN);
        }            
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }  
        return ans;
    }
};