class Solution {
public:
    //memoization
    // int cS(int n, vector<int>&dp){
    //     if(n<=1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=cS(n-1,dp)+cS(n-2,dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return cS(n,dp);
    // }
    
    
    //tabulation 
    // int climbStairs(int n){
    //     vector<int>dp(n+1,-1);
    //     dp[0]=1;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++)
    //         dp[i]=dp[i-1]+dp[i-2];
    //     return dp[n];
    // }
    
    
    //space optimization 
    int climbStairs(int n){
        int prev=1,prev2=1;
        for(int i=2;i<=n;i++){   
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};