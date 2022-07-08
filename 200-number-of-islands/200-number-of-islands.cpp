class Solution {
public:
    void f(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&grid){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || 
           vis[i][j] || grid[i][j]=='0') 
            return;
        vis[i][j]=true;
        f(i+1,j,vis,grid);
        f(i-1,j,vis,grid);
        f(i,j+1,vis,grid);
        f(i,j-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    f(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};