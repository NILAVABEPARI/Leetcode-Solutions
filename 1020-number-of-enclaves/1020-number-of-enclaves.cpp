class Solution {
public:
    void f(int i, int j, vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || !grid[i][j]) return;
        grid[i][j]=0;
        f(i+1,j,grid);
        f(i-1,j,grid);
        f(i,j+1,grid);
        f(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 || i==grid.size()-1 || j==grid[0].size()-1)
                    f(i,j,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cnt+=grid[i][j];
        }
        return cnt;
    }
};