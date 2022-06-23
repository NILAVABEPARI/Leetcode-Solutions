// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	//memoization
	int f(int N, vector<long long int>&dp){
	    if(N==1) return 2;
	    if(N==2) return 3;
	    if(dp[N]!=-1) return dp[N];
	    return dp[N]=(f(N-1,dp)+f(N-2,dp))%1000000007;
	}
	int TotalWays(int N){
	    // Code here
	    vector<long long int>dp(N+1,-1);
	    long long int temp=f(N,dp);
	    return ((temp*temp)%1000000007);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends