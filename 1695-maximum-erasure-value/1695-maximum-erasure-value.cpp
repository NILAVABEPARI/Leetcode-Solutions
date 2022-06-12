class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),cnt=0,maxi=0;
        unordered_set<int>st;
        while(r<n){
            if(st.count(nums[r])==0){
                cnt+=nums[r];
                st.insert(nums[r++]);
                maxi=max(maxi,cnt);
            }
            else{
                cnt-=nums[l];
                st.erase(nums[l++]);
            }
        }
        return maxi;
    }
};