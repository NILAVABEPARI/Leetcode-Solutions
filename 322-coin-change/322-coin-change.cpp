class Solution {
public:
    //memoization
    // int f(int ind, int amount, vector<int>& coins, vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(amount%coins[0]==0) return amount/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int ntake=f(ind-1,amount,coins,dp);
    //     int take=INT_MAX;
    //     if(coins[ind]<=amount) take=1+f(ind,amount-coins[ind],coins,dp);
    //     return dp[ind][amount]=min(take,ntake);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n=coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //     int ans = f(n-1,amount,coins,dp);
    //     if(ans>=1e9) return -1;
    //     return ans;
    // }
    
    
    //tabulation
    // int coinChange(vector<int>& coins, int amount){
    //     int n=coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,0));
    //     for(int i=0;i<=amount;i++){
    //         if(i%coins[0]==0) dp[0][i]=i/coins[0];
    //         else dp[0][i]=1e9;
    //     }
    //     for(int ind=1;ind<n;ind++){
    //         for(int t=1;t<=amount;t++){
    //             int ntake=dp[ind-1][t];
    //             int take=INT_MAX;
    //             if(coins[ind]<=t) take=1+dp[ind][t-coins[ind]];
    //             dp[ind][t]=min(take,ntake);
    //         }
    //     }
    //     int ans = dp[n-1][amount];
    //     if(ans>=1e9) return -1;
    //     return ans;
    // }
    
    
    
    //space optimization
    int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=amount;t++){
                int ntake=prev[t];
                int take=INT_MAX;
                if(coins[ind]<=t) take=1+curr[t-coins[ind]];
                curr[t]=min(take,ntake);
            }
            prev=curr;
        }
        int ans = prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};