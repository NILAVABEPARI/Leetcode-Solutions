class Solution {
public:
    //memoization
    // int recur(vector<int>&cost, int n, vector<int>&dp){
    //     if(n==0 || n==1) return cost[n];
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=cost[n]+min(recur(cost,n-1,dp),recur(cost,n-2,dp));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     vector<int>dp(n+1,-1);
    //     return min(recur(cost,n-1,dp),recur(cost,n-2,dp));
    // }
    
    
    //tabulation
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     vector<int>dp(n+1,0);
    //     for(int i=0;i<n;i++){
    //         if(i<=1) dp[i]=cost[i];
    //         else dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    //     }
    //     return min(dp[n-1],dp[n-2]);
    // }
    
    //space optimization
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(), prev2, prev1;
         prev2=cost[0]; prev1=cost[1];
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev2,prev1);
    }    
};