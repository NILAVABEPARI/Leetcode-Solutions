class Solution {
public:
    //memoization
    // int f(int ind, int buy, vector<int>& prices,int cap,vector<vector<vector<int>>>&dp){
    //     if(cap==0 || ind==prices.size()) 
    //         return 0;   
    //     if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    //     int profit=0;
    //     if(buy)
    //         profit=max(-prices[ind]+f(ind+1,0,prices,cap,dp), f(ind+1,1,prices,cap,dp));
    //     else
    //         profit=max(prices[ind]+f(ind+1,1,prices,cap-1,dp), f(ind+1,0,prices,cap,dp));
    //     return dp[ind][buy][cap]=profit;
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
    //     return f(0,1,prices,k,dp);
    // }
        
    
    //tabulation
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
//         //1st base case - cap = 0        
//         for(int ind=0;ind<=n;ind++){
//             for(int buy=0;buy<=1;buy++)
//                 dp[ind][buy][0]=0;            
//         }
//         //2nd base case - ind = n
//         for(int cap=0;cap<=k;cap++){
//             for(int buy=0;buy<=1;buy++)
//                 dp[n][buy][cap]=0;            
//         }        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<=k;cap++){
//                     int profit=0;
//                     if(buy)
//                         profit=max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
//                     else
//                         profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
//                     dp[ind][buy][cap]=profit;
//                 }                
//             }
//         }        
//         return dp[0][1][k];
//     }
       
    
    //space optimization
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>next(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        //no need to write base case as everything is set to 0        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit=0;
                    if(buy)
                        profit=max(-prices[ind]+next[0][cap], next[1][cap]);
                    else
                        profit=max(prices[ind]+next[1][cap-1],next[0][cap]);
                    curr[buy][cap]=profit;
                }                
            }
            next=curr;
        }        
        return next[1][k];
    }    
};