class Solution {
public:
    void f(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid2,
           vector<pair<int,int>>&ds){
        if(i>=grid2.size() || j>=grid2[0].size() || i<0 || j<0 || 
           vis[i][j] || grid2[i][j]==0) 
            return;
        vis[i][j]=true;
        ds.push_back({i,j});
        f(i+1,j,vis,grid2,ds);
        f(i-1,j,vis,grid2,ds);
        f(i,j+1,vis,grid2,ds);
        f(i,j-1,vis,grid2,ds);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0,n=grid2.size(),m=grid2[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<pair<int,int>>>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    vector<pair<int,int>>ds;
                    f(i,j,vis,grid2,ds);
                    arr.push_back(ds);          
                }
            }
        }
        for(auto &it:arr){
            bool flag=true;
            for(auto &i:it){
                int x=i.first,y=i.second;
                if(!grid1[x][y]){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};