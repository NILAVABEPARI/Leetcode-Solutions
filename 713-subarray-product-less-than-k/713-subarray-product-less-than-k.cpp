class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int cnt=0,n=nums.size(),left=0,prod=1;
        for(int right=0;right<n;right++){
            prod*=nums[right];
            while(prod>=k) prod/=nums[left++];
            cnt+=right-left+1;
        }
        return cnt;
    }
};