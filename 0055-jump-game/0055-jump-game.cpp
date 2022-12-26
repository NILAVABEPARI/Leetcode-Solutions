class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*int n=nums.size();
        int reach=0;
        for(int i=0;i<n;i++){
            if(i>reach) return false;
            reach=max(reach,nums[i]+i);      
        }
        if(reach>=n-1) return true;
        return false;*/
        
        //back loop
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=last)
                last=i;
        }
        return last==0;
    }
};