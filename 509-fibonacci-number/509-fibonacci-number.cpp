class Solution {
public:
    //memoization
    // int f(int n,vector<int>&dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=f(n-1,dp)+f(n-2,dp);
    // }
    // int fib(int n) {
    //     vector<int>dp(n+1,-1);
    //     return f(n,dp);
    // }
    
    //tabulation
    // int fib(int n){
    //     vector<int>dp(n+1,0);
    //     dp[0]=0;
    //     if(n>0) dp[1]=1;
    //     for(int i=2;i<=n;i++)
    //         dp[i]=dp[i-1]+dp[i-2];
    //     return dp[n];
    // }    
    
    //space optimization
    int fib(int n){
        if(n<=1) return n;
        int prev2=0,prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};