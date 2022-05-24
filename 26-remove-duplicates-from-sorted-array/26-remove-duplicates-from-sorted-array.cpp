class Solution {
public:
    //optimal
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[l]!=nums[r])  nums[++l]=nums[r];
            r++; 
        }        
        return l+1;
    }
};