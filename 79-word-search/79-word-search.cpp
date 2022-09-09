class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int i, int j){
        if(!word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || 
            board[i][j]!=word[0])
            return false;
        char temp=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        if(check(board,s,i+1,j) || check(board,s,i,j+1) || 
            check(board,s,i-1,j) || check(board,s,i,j-1))
            return true;
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && check(board,word,i,j))
                    return true;
            }            
        }
        return false;
    }
};