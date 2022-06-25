class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        int m=nums1.size(), n=nums2.size();
        vector<int>ans;
        st.push(nums2[n-1]);
        mp[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();                
            if(st.empty())
                mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            st.push(nums2[i]);            
        }        
        for(int i=0;i<m;i++)
            ans.push_back(mp[nums1[i]]);        
        return ans;
    }
};