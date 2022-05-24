class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,n=nums.size(),cnt=0,temp=0;
        while(i<n){
            while(i<n && nums[i]!=1) i++;
            while(i<n && nums[i]!=0) i++, temp++;
            cnt=max(cnt,temp);
            temp=0;
        }
        return cnt;
    }
};