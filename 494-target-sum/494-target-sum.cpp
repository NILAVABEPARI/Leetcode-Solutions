class Solution {
public:
    int f(int ind, int sum, vector<int> &arr, vector<vector<int>>&dp){
        if(ind==0){
            if(sum==0 && arr[0]==0) 
                return 2;
            if(sum==0 || sum == arr[0])    
                return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) 
            return dp[ind][sum];    
        int ntake=f(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum) 
            take=f(ind-1,sum-arr[ind],arr,dp);
        return dp[ind][sum]=(take+ntake);
    }
    int countPartitions(int n, int d, vector<int> &arr) {
        int tsum=0;
        for(auto &it:arr) tsum+=it;
        if((tsum-d<0) || (tsum-d)%2==1)
            return 0;
        int s2=(tsum-d)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return f(n-1,s2,arr,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};