class Solution {
public:
    //bture force
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>freq(n+1,0);
    //     for(int i=0;i<n;i++)
    //         freq[nums[i]]=1;
    //     for(int i=0;i<=n;i++){
    //         if(freq[i]==0) return i;
    //     }            
    //     return 1;
    // }
    
    //optimal
    int missingNumber(vector<int>& nums) {
        int result=nums.size();
        for(int i=0;i<nums.size();i++){
            result^=nums[i];
            result^=i;
        }
        return result;
    }
};