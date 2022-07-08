class Solution {
public:
    // bool f(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid){
    //     if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0)
    //         return false;
    //     if(vis[i][j] || grid[i][j]==1) return true;
    //     if(i==grid.size()-1 || j==grid[0].size()-1 || i==0 || j==0)
    //         return false;
    //     vis[i][j]=true;
    //     bool d1 = f(i+1,j,vis,grid);
    //     bool d2 = f(i-1,j,vis,grid);
    //     bool d3 = f(i,j+1,vis,grid);
    //     bool d4 = f(i,j-1,vis,grid);
    //     return d1 && d2 && d3 && d4;        
    // }
    // int closedIsland(vector<vector<int>>& grid) {
    //     int cnt=0,n=grid.size(),m=grid[0].size();
    //     vector<vector<bool>>vis(n,vector<bool>(m,false));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(!vis[i][j] && grid[i][j]==0 && f(i,j,vis,grid))                 
    //                 cnt++;             
    //         }
    //     }
    //     return cnt;
    // }
    
    
    //without the vis array -- changing the original grid
    bool f(int i, int j, vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return false;
        if(grid[i][j]==1) return true;
        //this case is not required because if it reaches out of bound the the prev node was 0
        // if(i==grid.size()-1 || j==grid[0].size()-1 || i==0 || j==0)
        //     return false;
        grid[i][j]=1;
        bool d1 = f(i+1,j,grid);
        bool d2 = f(i-1,j,grid);
        bool d3 = f(i,j+1,grid);
        bool d4 = f(i,j-1,grid);
        return d1 && d2 && d3 && d4;        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && f(i,j,grid))
                    cnt++;                
            }
        }
        return cnt;
    }
};