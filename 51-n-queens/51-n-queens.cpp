class Solution {
    public:
    /*bool isSafe(int row, int col, int n,vector<string>board){
        //upper diagonal
        int x=row,y=col;
        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q') return false;
        }
        //left of that row        
        row=x,col=y;
        while(col>=0){
            if(board[row][col--]=='Q') return false;
        }
        //lower diagonal
        row=x,col=y;
        while(row<n && col>=0){
            if(board[row++][col--]=='Q') return false;
        }
        return true;
    }
    void recur(int col, int n, vector<string>&board, vector<vector<string>>&ans) {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col]='Q';
                recur(col+1,n,board,ans);
                board[row][col]='.';
            }
        }        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        recur(0,n,board,ans);
        return ans;
    }*/
    
    
    //optimised
    void recur(int col, int n, vector<string>&board, vector<vector<string>>&ans,
                 vector<int>&leftRow,vector<int>&upperDia,
                 vector<int>&lowerDia){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDia[row+col]==0 && upperDia[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDia[row+col]=1; 
                upperDia[n-1+col-row]=1;
                recur(col+1,n,board,ans,leftRow,upperDia,lowerDia);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDia[row+col]=0; 
                upperDia[n-1+col-row]=0;
            }
        }        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<int> leftRow(n,0), upperDia(2*n-1,0),lowerDia(2*n-1,0);
        recur(0,n,board,ans,leftRow,upperDia,lowerDia);
        return ans;
    }
};