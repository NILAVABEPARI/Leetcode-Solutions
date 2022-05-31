class Solution {
public:
    //memoization - TLE
    // int lcs(string s1, string s2, int n, int m,vector<vector<int>>&dp){
    //     if(n==0 || m==0) return 0;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     if(s1[n-1]==s2[m-1])
    //         return dp[n][m] = 1 + lcs(s1,s2,n-1,m-1,dp);
    //     return dp[n][m] = max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
    // } 
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m=text1.size(),n=text2.size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     return lcs(text1,text2,m,n,dp);
    // }
           
    
    //tabulation
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size(),m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int i=0;i<=m;i++) dp[0][i]=0;
//         for(int i=0;i<=n;i++) dp[i][0]=0;        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(text1[i-1]==text2[j-1])
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }            
//         }
//         return dp[n][m];
//     }
    
    
    //space optimization
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>prev(m+1,0);
        for(int i=0;i<=m;i++) prev[i]=0;        
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }   
            prev=curr;
        }
        return prev[m];
    }
};