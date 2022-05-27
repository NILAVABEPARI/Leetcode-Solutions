// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //memoization
    // bool f(int i, int sum, vector<int>arr,vector<vector<int>>&dp){
    //     if(sum==0) return true;
    //     if(i==0) return (arr[0]==sum);
    //     if(dp[i][sum]!=-1) return dp[i][sum];
        
    //     bool ntake=f(i-1,sum,arr,dp);
    //     bool take=false;
    //     if(arr[i]<=sum)
    //         take=f(i-1,sum-arr[i],arr,dp);
    //     return dp[i][sum]=take or ntake;
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     // code here 
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    //     return f(arr.size()-1,sum,arr,dp);
    // }
    
    
    //tabulation
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n=arr.size();
    //     vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        
    //     for(int i=0;i<n;i++) dp[i][0]=1;
    //     dp[0][arr[0]]=1;
        
    //     for(int i=1;i<n;i++){
    //         for(int tar=1;tar<=sum;tar++){
    //             bool ntake=dp[i-1][tar];
    //             bool take=false;
    //             if(arr[i]<=tar)
    //                 take=dp[i-1][tar-arr[i]];
    //             dp[i][tar]=take or ntake;
    //         }
    //     }
    //     return dp[n-1][sum];
    // }
    
    
    //space optimization
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool>prev(sum+1,0);
        
        for(int i=0;i<n;i++) prev[0]=1;
        prev[arr[0]]=1;
        
        for(int i=1;i<n;i++){
            vector<bool>curr(sum+1,0);
            for(int tar=1;tar<=sum;tar++){
                bool ntake=prev[tar];
                bool take=false;
                if(arr[i]<=tar)
                    take=prev[tar-arr[i]];
                curr[tar]=take or ntake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends