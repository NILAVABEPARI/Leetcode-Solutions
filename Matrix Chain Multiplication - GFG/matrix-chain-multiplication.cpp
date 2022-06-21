// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //memoization
    // int f(int i, int j, int arr[], vector<vector<int>>&dp){
    //     if(i==j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int mini=1e9;
    //     for(int k=i;k<j;k++){
    //         int steps=arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
    //         if(steps<mini) mini=steps;
    //     }
    //     return dp[i][j]=mini;
    // }
    
    // int matrixMultiplication(int N, int arr[]){
    //     // code here
    //     vector<vector<int>>dp(N,vector<int>(N,-1));
    //     return f(1,N-1,arr,dp);
    // }
    
    
    //tabulation
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i=1;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    if(steps<mini) mini=steps;
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends