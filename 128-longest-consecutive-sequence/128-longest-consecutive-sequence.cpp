class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
            st.insert(nums[i]);        
        int ans=0;
        for(int i=0;i<n;i++) {
            if(st.find(nums[i]-1)==st.end()){
                int currentNum=nums[i];
                int currentStreak = 1;
                while(st.find(currentNum+1)!=st.end()){
                    currentStreak+=1;
                    currentNum+=1;
                }
                ans=max(ans,currentStreak);
            }       
        }
        return ans;
    }
};