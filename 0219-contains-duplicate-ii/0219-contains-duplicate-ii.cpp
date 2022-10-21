class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;        
        if(k==0) return false;
        if(k>=n) k=n-1;
        for(int i=0;i<n;i++){
            if(i>k) st.erase(nums[i-k-1]);
            if(st.count(nums[i])) return true;            
            st.insert(nums[i]);
        }
        return false;
    }
};