class Solution {
public:
    //using LIS
    // bool increasingTriplet(vector<int>& nums) {
    //     int len=1,n=nums.size();
    //     vector<int>temp;
    //     temp.push_back(nums[0]);
    //     for(int i=1;i<n;i++){
    //         if(temp.back()<nums[i]){
    //             len++;
    //             temp.push_back(nums[i]);                
    //         }
    //         else{
    //             int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
    //             temp[ind]=nums[i];
    //         }
    //         if(temp.size()==3) return true;
    //     }
    //     return false;
    // }
    
    
    //using 3 variables
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),f=INT_MAX,s=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=f) f=nums[i];
            else if(nums[i]<=s) s=nums[i];
            else return true;
        }
        return false;
    }
};