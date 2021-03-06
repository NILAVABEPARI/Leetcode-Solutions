class Solution {
public:
    //top down - memoization
    // int recur(vector<int>& nums,int n,vector<int>&dp){
    //     if(n==0) return nums[n];
    //     if(n<0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int pick=nums[n]+recur(nums,n-2,dp);
    //     int n_pick=recur(nums,n-1,dp);
    //     return dp[n]=max(pick,n_pick);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     return recur(nums,n-1,dp);
    // }
    
    //bottom up - tabulation
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //     dp[0]=nums[0];
    //     for(int i=1;i<n;i++){
    //         int pick=nums[i];
    //         if(i>1) pick+=dp[i-2];
    //         int n_pick=dp[i-1];
    //         dp[i]=max(pick,n_pick);
    //     }
    //     return dp[n-1];
    // }
    
    
    //space optimization
    int rob(vector<int>& nums){
        int n=nums.size();
        int prev2=0,prev1=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int n_pick=prev1;
            int curr=max(pick,n_pick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};