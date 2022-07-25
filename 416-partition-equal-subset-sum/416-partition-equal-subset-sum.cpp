class Solution {
public:
    //memoization -- TLE
    // bool f(int i, int sum, vector<int>arr,vector<vector<int>>&dp){
    //     if(sum==0) return true;
    //     if(i==0) return (arr[0]==sum);
    //     if(dp[i][sum]!=-1) return dp[i][sum];
    //     bool ntake=f(i-1,sum,arr,dp);
    //     bool take=false;
    //     if(arr[i]<=sum)
    //         take=f(i-1,sum-arr[i],arr,dp);
    //     return dp[i][sum]=take or ntake;
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    //     return f(arr.size()-1,sum,arr,dp);
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size(),sum=0;
    //     for(int i=0;i<n;i++) sum+=nums[i];
    //     if(sum%2) return false;
    //     return isSubsetSum(nums,sum/2);
    // }
    
    
    //tabulation
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                bool ntake=dp[i-1][tar];
                bool take=false;
                if(arr[i]<=tar)
                    take=dp[i-1][tar-arr[i]];
                dp[i][tar]=take or ntake;
            }
        }
        return dp[n-1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        return isSubsetSum(nums,sum/2);        
    }
    
    
    //space optimized
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n=arr.size();
    //     vector<bool>prev(sum+1,0),curr(sum+1,0);        
    //     prev[0]=curr[0]=1;
    //     if(arr[0]<=sum) prev[arr[0]]=1;
    //     for(int i=1;i<n;i++){            
    //         for(int tar=1;tar<=sum;tar++){
    //             bool ntake=prev[tar];
    //             bool take=false;
    //             if(arr[i]<=tar)
    //                 take=prev[tar-arr[i]];
    //             curr[tar]=take or ntake;
    //         }
    //         prev=curr;
    //     }
    //     return prev[sum];
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size(),sum=0;
    //     for(int i=0;i<n;i++) sum+=nums[i];
    //     if(sum%2!=0) return false;
    //     return isSubsetSum(nums,sum/2);
    // }
};