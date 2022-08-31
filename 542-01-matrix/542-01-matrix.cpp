class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
	    
	    vector<vector<bool>>vis(n,vector<bool>(m,false));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>>q;    //(i,j),dist
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        
        int delRow[]={0,0,1,-1};
        int delCol[]={1,-1,0,0};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            dist[row][col]=dis;
            
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
        
	    return dist;
    }
};