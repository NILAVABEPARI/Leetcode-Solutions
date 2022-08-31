class Solution {
public:
    //dfs traversal
    // void f(int i, int j, vector<vector<int>>&grid){
    //     if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || !grid[i][j]) return;
    //     grid[i][j]=0;
    //     f(i+1,j,grid);
    //     f(i-1,j,grid);
    //     f(i,j+1,grid);
    //     f(i,j-1,grid);
    // }
    // int numEnclaves(vector<vector<int>>& grid) {
    //     int cnt=0,n=grid.size(),m=grid[0].size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i*j==0 || i==grid.size()-1 || j==grid[0].size()-1)
    //                 f(i,j,grid);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++)
    //             cnt+=grid[i][j];
    //     }
    //     return cnt;
    // }
    
    
    //bfs traversal
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){  
                        q.push({i,j});
                        vis[i][j]=true;
                    }else vis[i][j]=false; 
                }
            }
        }
        int delRow[]={0,0,1,-1};
        int delCol[]={1,-1,0,0};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                   !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]) 
                    cnt++;
            }
        }
        return cnt;
    }
};