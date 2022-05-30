class Solution {
public:
    //memoization
    // int f(int ind, int sum, vector<int> &arr, vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(sum==0 && arr[0]==0) 
    //             return 2;
    //         if(sum==0 || sum == arr[0])    
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[ind][sum]!=-1) 
    //         return dp[ind][sum];    
    //     int ntake=f(ind-1,sum,arr,dp);
    //     int take=0;
    //     if(arr[ind]<=sum) 
    //         take=f(ind-1,sum-arr[ind],arr,dp);
    //     return dp[ind][sum]=(take+ntake);
    // }
    // int countPartitions(int n, int d, vector<int> &arr) {
    //     int tsum=0;
    //     for(auto &it:arr) tsum+=it;
    //     if((tsum-d<0) || (tsum-d)%2==1)
    //         return 0;
    //     int s2=(tsum-d)/2;
    //     vector<vector<int>>dp(n,vector<int>(s2+1,-1));
    //     return f(n-1,s2,arr,dp);
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return countPartitions(nums.size(),target,nums);
    // }
    
    
    //tabulation
//     int f(vector<int> &num, int sum){
//         int n = num.size();
//         vector<vector<int>> dp(n,vector<int>(sum+1,0));    
//         if(num[0] == 0) dp[0][0] = 2;  // 2 cases -pick and not pick
//         else dp[0][0] = 1;  // 1 case - not pick    
//         if(num[0]!=0 && num[0]<=sum) dp[0][num[0]] = 1;  // 1 case -pick
//         for(int ind = 1; ind<n; ind++){
//             for(int target= 0; target<=sum; target++){            
//                 int notTaken = dp[ind-1][target];    
//                 int taken = 0;
//                 if(num[ind]<=target)
//                     taken = dp[ind-1][target-num[ind]];        
//                 dp[ind][target]= (notTaken + taken);
//             }
//         }
//         return dp[n-1][sum];
//     }
//     int countPartitions(int n, int d, vector<int> &arr){
//         int tsum=0;
//         for(auto &it:arr) tsum+=it;
//         if((tsum-d<0) || (tsum-d)%2==1)  return 0;
//         int s2=(tsum-d)/2;
//         return f(arr,s2);
//     }
//     int findTargetSumWays(vector<int>& nums, int target){
//         return countPartitions(nums.size(),target,nums);
//     }
    
    
    //space optimization
    int f(vector<int> &num, int sum){
        int n = num.size();
        vector<int> prev(sum+1,0);
        if(num[0] == 0) prev[0] = 2;  // 2 cases -pick and not pick
        else prev[0] = 1;  // 1 case - not pick    
        if(num[0]!=0 && num[0]<=sum) prev[num[0]] = 1;  // 1 case -pick
        for(int ind = 1; ind<n; ind++){
            vector<int>curr(sum+1,0);
            for(int target= 0; target<=sum; target++){            
                int notTaken = prev[target];
                int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];        
                curr[target]= (notTaken + taken);
            }
            prev=curr;
        }
        return prev[sum];
    }
    int countPartitions(int n, int d, vector<int> &arr){
        int tsum=0;
        for(auto &it:arr) tsum+=it;
        if((tsum-d<0) || (tsum-d)%2==1)  return 0;
        int s2=(tsum-d)/2;
        return f(arr,s2);
    }
    int findTargetSumWays(vector<int>& nums, int target){
        return countPartitions(nums.size(),target,nums);
    }
};