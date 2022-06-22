class Solution {    
public:
    //memoization
    // int f(int left, int right, vector<vector<int>>&dp, vector<int>&nums){
    //     if(left>right) return 0;
    //     if(dp[left][right]!=-1) return dp[left][right];
    //     int maxi=INT_MIN;
    //     for(int i=left;i<=right;i++){
    //         int cost=(nums[left-1]*nums[i]*nums[right+1]) + 
    //             + f(left, i-1, dp, nums) + f(i+1, right, dp, nums);
    //         maxi=max(maxi,cost);
    //     }        
    //     return dp[left][right]=maxi;
    // }
    // int maxCoins(vector<int>& nums) {
    //     int n=nums.size();
    //     nums.push_back(1);
    //     nums.insert(nums.begin(),1);
    //     vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
    //     return f(1,n,dp,nums);
    // }
    
    
    //tabulation
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        //base case not required - everything set to 0        
        for(int left=n;left>=1;left--){
            for(int right=1;right<=n;right++){
                if(left>right) continue;
                int maxi=INT_MIN;
                for(int ind=left;ind<=right;ind++){
                    int cost=(nums[left-1]*nums[ind]*nums[right+1]) + 
                        + dp[left][ind-1] + dp[ind+1][right];
                    maxi=max(maxi,cost);
                }
                dp[left][right]=maxi;
            }
        }
        return dp[1][n];
    }
};