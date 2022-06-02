class Solution {
public:
    void LIS(vector<int>& nums, vector<int>&temp){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi=1,lastInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i;
            }
        }
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd=hash[lastInd];
            temp.push_back(nums[lastInd]);        
        }
        reverse(temp.begin(),temp.end());
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>temp;
        LIS(nums,temp);
        return temp;
    }
};