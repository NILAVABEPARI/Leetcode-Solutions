// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
  bool f(int i, int sum, int arr[],vector<vector<int>>&dp){
        if(sum==0) return dp[i][sum]=true;
        if(i==0) return dp[i][sum] = (arr[0]==sum);
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool ntake=f(i-1,sum,arr,dp);
        bool take=false;
        if(arr[i]<=sum)
            take=f(i-1,sum-arr[i],arr,dp);
        return dp[i][sum]=take or ntake;
    }
    int minDifference(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        for (int i = 0; i <= sum; i++) 
            bool flag=f(n-1,i,arr,dp);
        
        int mini = 1e9;
        for (int i = 0; i <= sum/2; i++) {
            if (dp[n - 1][i] == true) {
                int diff = abs(i - (sum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
    
    
// 	int minDifference(int arr[], int n)  { 
// 	    int sum=0;
//         for(int i=0;i<n;i++) sum+=arr[i];
//         vector<bool>prev(sum+1,0),curr(sum+1,0);
//         prev[0]=curr[0]=1;
//         if(arr[0]<=sum) prev[arr[0]]=1;
//         for(int i=1;i<n;i++){
//             for(int tar=1;tar<=sum;tar++){
//                 bool ntake=prev[tar];
//                 bool take=false;
//                 if(arr[i]<=tar)
//                     take=prev[tar-arr[i]];
//                 curr[tar]=take or ntake;
//             }
//             prev=curr;
//         }
//         int mini=1e9;
//         for(int s1=0;s1<=sum/2;s1++){
//             if(prev[s1]){
//                 mini=min(mini,abs((sum-s1)-s1));
//             }
//         }
//         return mini;
// 	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends