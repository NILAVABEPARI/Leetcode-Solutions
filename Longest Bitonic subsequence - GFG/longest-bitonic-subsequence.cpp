// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void LIS(vector<int>& nums, vector<int>&dp){
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
                    dp[i]=1+dp[prev];                
            }
        }
    }
	int LongestBitonicSequence(vector<int>nums){
	    // code here
	    int n=nums.size();
	    vector<int>dp1(n,1),dp2(n,1),biotonic(n);
	    LIS(nums,dp1);
	    reverse(nums.begin(),nums.end());
	    LIS(nums,dp2);
	    reverse(dp2.begin(),dp2.end());
	    
	    
	    int maxi=1;
	    for(int i=0;i<n;i++){
	        biotonic[i]=dp1[i]+dp2[i]-1;
	        maxi=max(maxi,biotonic[i]);
	    }
	    return maxi;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends