class Solution {
public:
    //memoization
    // int f(int i, int j, string s1, string s2,vector<vector<int>>&dp){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j])
    //         return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    //     else{
    //         //insert
    //         int ins=1+f(i,j-1,s1,s2,dp);
    //         //delete
    //         int del=1+f(i-1,j,s1,s2,dp);
    //         //replace
    //         int rep=1+f(i-1,j-1,s1,s2,dp);
    //         return dp[i][j]=min(ins,min(del,rep));
    //     }
    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length(),m=word2.length();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,word1,word2,dp);
    // }
    
    //tabulation
//     int minDistance(string s1, string s2) {
//         int n=s1.length(),m=s2.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         //base case
//         for(int i=0;i<=n;i++) dp[i][0]=i;
//         for(int j=0;j<=m;j++) dp[0][j]=j;
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1])
//                     dp[i][j]=dp[i-1][j-1];
//                 else{
//                     //insert
//                     int ins=1+dp[i][j-1];
//                     //delete
//                     int del=1+dp[i-1][j];
//                     //replace
//                     int rep=1+dp[i-1][j-1];
//                     dp[i][j]=min(ins,min(del,rep));
//                 }
//             }            
//         }        
//         return dp[n][m];
//     }
    
    //space optimization
    int minDistance(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        //base case
        for(int j=0;j<=m;j++) prev[j]=j;
        
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]=prev[j-1];
                else{
                    //insert
                    int ins=1+curr[j-1];
                    //delete
                    int del=1+prev[j];
                    //replace
                    int rep=1+prev[j-1];
                    curr[j]=min(ins,min(del,rep));
                }
            }  
            prev=curr;
        }        
        return prev[m];
    }
};