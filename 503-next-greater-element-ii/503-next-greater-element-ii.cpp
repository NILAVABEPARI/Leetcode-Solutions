class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        st.push(nums[n-1]);
        ans[n-1]=-1;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
               st.pop(); 
            }
            if(st.empty()) ans[i%n]=-1;
            else ans[i%n]=st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }
};