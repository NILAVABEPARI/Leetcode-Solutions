class Solution {
public:
    //memoization
    // int f(int ind, vector<int>&nums, int k,  vector<int>&dp){
    //     if(ind==0) return dp[ind]=nums[0];
    //     if(dp[ind]!=-1) return dp[ind];
    //     int maxi=-1e9;
    //     for(int i=1;i<=k;i++){
    //         if(ind-i>=0){
    //             int temp=f(ind-i,nums,k,dp) + nums[ind];
    //             maxi=max(maxi,temp);
    //         }
    //     }
    //     return dp[ind]=maxi;
    // }
    // int maxResult(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     return f(n-1,nums,k,dp);
    // }
    
    
    //tabulation
    // int maxResult(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //     dp[0]=nums[0];
    //     for(int i=1;i<n;i++){
    //         int maxi=-1e9;
    //         for(int j=1;j<=k;j++){
    //             int temp=nums[i];
    //             if(i-j>=0)  temp+=dp[i-j];
    //             maxi=max(maxi,temp);
    //         }
    //         dp[i]=maxi;
    //     }
    //     return dp[n-1];
    // }
    
    
    //space optimized
    int maxResult(vector<int>& nums, int k) {
	vector<int> dp(size(nums), INT_MIN);
        multiset<int> s ({ dp[0] = nums[0] });// set dp[0] = nums[0] and insert it into set
        for(int i = 1; i < size(nums); i++) {
            if(i > k) 
                // erase elements from which we cant jump to current index
                s.erase(s.find(dp[i - k - 1]));  
            // choose element with max score and jump from that to the current index
            s.insert(dp[i] = *rbegin(s) + nums[i]);    
        }
        return dp.back();
    }
};