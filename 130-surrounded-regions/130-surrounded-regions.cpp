class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> mat,vector<vector<bool>>&vis){
        if(i>=mat.size() || i<0 || j>=mat[0].size() || j<0 || vis[i][j] || mat[i][j]=='X') return;
        vis[i][j]=true;
        dfs(i+1,j,mat,vis);
        dfs(i-1,j,mat,vis);
        dfs(i,j+1,mat,vis);
        dfs(i,j-1,mat,vis);
    }
    void solve(vector<vector<char>>&mat){
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        //traverse rows
        for(int j=0;j<m;j++){
            //first row
            if(mat[0][j]=='O' && !vis[0][j]) dfs(0,j,mat,vis);
            //last row
            if(mat[n-1][j]=='O' && !vis[n-1][j]) dfs(n-1,j,mat,vis);
        }
        
        //traverse cols
        for(int i=0;i<n;i++){
            //first col
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,mat,vis);
            //last col
            if(mat[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,mat,vis);
        }
        
        //update matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j])
                    mat[i][j]='X';
            }
        }
    }
};