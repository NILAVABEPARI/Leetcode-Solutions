// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //memoization 
    // int f(int ind, int W, int val[], int wt[],vector<vector<int>>&dp){
    //     if(ind==0)
    //         return (W/wt[0])*val[0];
    //     if(dp[ind][W]!=-1) return dp[ind][W];
    //     int ntake=f(ind-1,W,val,wt,dp);
    //     int take=INT_MIN; 
    //     if(wt[ind]<=W)
    //         take=val[ind]+f(ind,W-wt[ind],val,wt,dp);
    //     return dp[ind][W]=max(take,ntake);
    // }
    // int knapSack(int n, int W, int val[], int wt[]){
    //     vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    //     return f(n-1,W,val,wt,dp); 
    // }
    
    
    //tabulation
    // int knapSack(int n, int W, int val[], int wt[]){
    //     vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    //     for(int i=wt[0];i<=W;i++)
    //         dp[0][i]=((int)(i/wt[0]))*val[0];
    //     for(int ind=1;ind<n;ind++){
    //         for(int w=0;w<=W;w++){
    //             int ntake=dp[ind-1][w];
    //             int take=INT_MIN;
    //             if(wt[ind]<=w)
    //                 take=val[ind]+dp[ind][w-wt[ind]];
    //             dp[ind][w]=max(take,ntake);
    //         }
    //     }
    //     return dp[n-1][W];
    // }
    
    
    // //space optimization
    // int knapSack(int n, int W, int val[], int wt[]){
    //     vector<int>prev(W+1,0), curr(W+1,0);
    //     for(int i=wt[0];i<=W;i++)
    //         prev[i]=((int)(i/wt[0]))*val[0];
    //     for(int ind=1;ind<n;ind++){
    //         for(int w=0;w<=W;w++){
    //             int ntake=prev[w];
    //             int take=INT_MIN;
    //             if(wt[ind]<=w)
    //                 take=val[ind]+curr[w-wt[ind]];
    //             curr[w]=max(take,ntake);
    //         }
    //         prev=curr;
    //     }
    //     return prev[W];
    // }
    
    
    //single array SO
    int knapSack(int n, int W, int val[], int wt[]){
        vector<int>prev(W+1,0);
        for(int i=wt[0];i<=W;i++)
            prev[i]=((int)(i/wt[0]))*val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int ntake=prev[w];
                int take=INT_MIN;
                if(wt[ind]<=w)
                    take=val[ind]+prev[w-wt[ind]];
                prev[w]=max(take,ntake);
            }
        }
        return prev[W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends