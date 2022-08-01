class Solution {
public:
    int f(int floors, int eggs,vector<vector<int>>&dp){
        if (eggs == 1 || floors <= 1) return floors;
        if(dp[floors][eggs]!=-1) return dp[floors][eggs];
        int res=INT_MAX;
        for(int flr=1;flr<=floors;flr++){
            int b=f(flr-1,eggs-1,dp);
            int nb=f(floors-flr,eggs,dp);
            res=min(res,1+max(b,nb));
        }
        return dp[floors][eggs]=res;
    }
    int twoEggDrop(int n) {
        int eggs=2;
        vector<vector<int>>dp(n+1,vector<int>(eggs+1,-1));
        return f(n,eggs,dp);
    }
};