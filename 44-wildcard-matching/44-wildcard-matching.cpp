class Solution {
public:
    //memoization -- NOT WORKING
    // int f(int i, int j, string s, string p,vector<vector<int>>&dp){
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0 && i>=0){
    //         for(int x=0;x<=i;x++){
    //             if(s[x]!='*') 
    //                 return false;
    //         }
    //         return true;
    //     }        
    //     if(dp[i][j]!=-1) return dp[i][j];        
    //     if(s[i]==p[j] || s[i]=='?') 
    //         return dp[i][j]=f(i-1,j-1,s,p,dp);
    //     if(s[i]=='*') 
    //         return dp[i][j]=f(i-1,j,s,p,dp) or f(i,j-1,s,p,dp);
    //     return dp[i][j]=false;
    // }
    // bool isMatch(string s, string p) {
    //     int n=s.length(),m=p.length();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,s,p,dp);
    // }
    
    //tabulaiton
    bool isMatch(string text, string pattern){
        int n=pattern.length(),m=text.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++) dp[0][j]=false;
                               
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(pattern[ii-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        } 
                               
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pattern[i-1]==text[j-1] || pattern[i-1]=='?') 
                    dp[i][j]=dp[i-1][j-1];
                else if(pattern[i-1]=='*') 
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                else dp[i][j]=false;
            }     
        }  
        return dp[n][m];
    }
};