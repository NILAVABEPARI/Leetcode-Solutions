class Solution {
public:
    //memoization -- TLE -- all test cases passed
    // int f(int ind, int prev, vector<int>&nums, vector<vector<int>>&dp){
    //     if(ind==nums.size()) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int ntake=0+f(ind+1,prev,nums,dp);
    //     int take=0;
    //     if(prev==-1 || nums[ind]>nums[prev]) take=1+f(ind+1,ind,nums,dp);
    //     return dp[ind][prev+1]=max(take,ntake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,nums,dp);
    // }
    
    
    //tabulation
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev=ind-1;prev>=-1;prev--){
    //             int ntake=0+dp[ind+1][prev+1];
    //             int take=0;
    //             if(prev==-1 || nums[ind]>nums[prev]) 
    //                 take=1+dp[ind+1][ind+1];
    //             dp[ind][prev+1]=max(take,ntake);
    //         }
    //     }      
    //     return dp[0][-1+1];
    // }
    
    
    //space optimization
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>next(n+1,0),curr(n+1,0);
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev=ind-1;prev>=-1;prev--){
    //             int ntake=0+next[prev+1];
    //             int take=0;
    //             if(prev==-1 || nums[ind]>nums[prev]) 
    //                 take=1+next[ind+1];
    //             curr[prev+1]=max(take,ntake);
    //         }
    //         next=curr;
    //     }      
    //     return next[-1+1];
    // }
    
    
    //printing the LIS
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n,1),hash(n);
    //     int maxi=1,lastInd=0;
    //     for(int i=0;i<n;i++){
    //         hash[i]=i;
    //         for(int prev=0;prev<i;prev++){
    //             if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
    //                 dp[i]=1+dp[prev];
    //                 hash[i]=prev;
    //             }
    //         }
    //         if(dp[i]>maxi){
    //             maxi=dp[i];
    //             lastInd=i;
    //         }
    //     }        
    //     vector<int>temp;
    //     temp.push_back(nums[lastInd]);
    //     while(hash[lastInd]!=lastInd){
    //         lastInd=hash[lastInd];
    //         temp.push_back(nums[lastInd]);        
    //     }
    //     reverse(temp.begin(),temp.end());
    //     for(auto &it:temp) cout<<it<<" ";
    //     cout<<endl;
    //     return maxi;
    // }
    
    
    //binary search
    int lengthOfLIS(vector<int>& nums){
        int len=1,n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<nums[i]){
                len++;
                temp.push_back(nums[i]);                
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }    
};