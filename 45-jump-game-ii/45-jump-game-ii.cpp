class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currReach=0,jumps=0,maxR=0;
        for(int i=0;i<n-1;i++){
            maxR=max(maxR,i+nums[i]);
            if(i==currReach){
                jumps++;
                currReach=maxR;
            }
        }
        return jumps;
    }
};