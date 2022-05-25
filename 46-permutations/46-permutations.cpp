class Solution {
    //brute force
    public:
    void recur(vector<int>&ds, vector<vector<int>>&ans, vector<int>&freq,
               vector<int>&nums){
        if(ds.size()==nums.size())  {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                recur(ds,ans,freq,nums);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<int> freq(nums.size(),0);
        recur(ds,ans,freq,nums);        
        return ans;
    }
    
    
    // public:
    // void recur(int ind, vector<vector<int>>&ans, vector<int>&nums)    {
    //     if(ind==nums.size())        {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int i=ind;i<nums.size();i++)        {
    //         swap(nums[ind],nums[i]);
    //         recur(ind+1,ans,nums);
    //         swap(nums[i],nums[ind]);
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     recur(0,ans,nums);
    //     return ans;
    // }    
};