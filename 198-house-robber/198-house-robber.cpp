class Solution {
public:
    //top down - memoization
    int recur(vector<int>& nums,int n,vector<int>&dp){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+recur(nums,n-2,dp);
        int n_pick=recur(nums,n-1,dp);
        return dp[n]=max(pick,n_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return recur(nums,n-1,dp);
    }
    
    //bottom up - tabulation
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //     dp[0]=nums[0];
    //     if(n>=2)
    //         dp[1]=max(nums[1],nums[0]);
    //     for(int i=2;i<n;i++){
    //         dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    //     }
    //     return dp[n-1];
    // }
};