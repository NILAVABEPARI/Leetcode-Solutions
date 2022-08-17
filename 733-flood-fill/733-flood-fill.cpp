class Solution {
public:
    void dfs(vector<vector<int>>& image, int value, int sr, int sc, int newColor){
        if(sr>=image.size() || sc>=image[0].size() || 
           sr<0 || sc<0 || image[sr][sc]!=value)
            return;
        image[sr][sc]=newColor;
        dfs(image, value, sr, sc-1, newColor);
        dfs(image, value, sr, sc+1, newColor);
        dfs(image, value, sr-1, sc, newColor);
        dfs(image, value, sr+1, sc, newColor);        
    }
    
    void bfs(vector<vector<int>>& ans, int value, int sr, int sc, int newColor){
        ans[sr][sc]=newColor;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow<ans.size() && ncol<ans[0].size() && nrow>=0 && ncol>=0 
                && ans[nrow][ncol]==value){
                    ans[nrow][ncol]=newColor;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) //to avoid infinite loop
            bfs(image, image[sr][sc], sr, sc, newColor);            
            // dfs(image, image[sr][sc], sr, sc, newColor);
        return image;
    }
};