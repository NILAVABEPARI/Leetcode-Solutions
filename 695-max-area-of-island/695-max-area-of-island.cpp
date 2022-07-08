class Solution {
public:
    void f(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid, int &cnt){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || 
           vis[i][j] || grid[i][j]==0) 
            return;
        vis[i][j]=true; cnt++;
        f(i+1,j,vis,grid,cnt);
        f(i-1,j,vis,grid,cnt);
        f(i,j+1,vis,grid,cnt);
        f(i,j-1,vis,grid,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0,n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int cnt=0;
                    f(i,j,vis,grid,cnt);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};