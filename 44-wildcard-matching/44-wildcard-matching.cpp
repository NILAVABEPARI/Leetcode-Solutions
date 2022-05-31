class Solution {
public:
    //memoization -- TLE 2 test cases remaining
    // int f(int i, int j, string pattern, string text, vector<vector<int>>&dp){
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0 && i>=0){
    //         for(int x=0;x<=i;x++){
    //             if(pattern[x]!='*') 
    //                 return false;
    //         }
    //         return true;
    //     }        
    //     if(dp[i][j]!=-1) return dp[i][j];        
    //     if(pattern[i]==text[j] || pattern[i]=='?') 
    //         return dp[i][j]=f(i-1,j-1,pattern,text,dp);
    //     if(pattern[i]=='*') 
    //         return dp[i][j]=f(i-1,j,pattern,text,dp) or f(i,j-1,pattern,text,dp);
    //     return dp[i][j]=false;
    // }
    // bool isMatch(string text, string pattern) {
    //     int n=pattern.length(),m=text.length();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,pattern,text,dp);
    // }
    
    //tabulaiton
//     bool isMatch(string text, string pattern){
//         int n=pattern.length(),m=text.length();
//         vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
//         dp[0][0]=true;
//         for(int j=1;j<=m;j++) dp[0][j]=false;
                               
//         for(int i=1;i<=n;i++){
//             bool flag=true;
//             for(int ii=1;ii<=i;ii++){
//                 if(pattern[ii-1]!='*'){
//                     flag=false;
//                     break;
//                 }
//             }
//             dp[i][0]=flag;
//         } 
                               
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(pattern[i-1]==text[j-1] || pattern[i-1]=='?') 
//                     dp[i][j]=dp[i-1][j-1];
//                 else if(pattern[i-1]=='*') 
//                     dp[i][j]=dp[i-1][j] | dp[i][j-1];
//                 else dp[i][j]=false;
//             }     
//         }  
//         return dp[n][m];
//     }
    
    
    //space optimization
    bool isAllStars(string S1, int i){
        for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string text, string pattern){
        int n=pattern.length(),m=text.length();
        vector<bool>prev(m+1,false),curr(m+1,false);
        prev[0]=true;
                                             
        for(int i=1;i<=n;i++){
            curr[0] = isAllStars(pattern, i);
            for(int j=1;j<=m;j++){
                if(pattern[i-1]==text[j-1] || pattern[i-1]=='?') 
                    curr[j]=prev[j-1];
                else if(pattern[i-1]=='*') 
                    curr[j]=prev[j] | curr[j-1];
                else curr[j]=false;
            }     
            prev=curr;
        }  
        return prev[m];
    }
};