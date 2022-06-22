// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int mod = 1e9 + 7;
    int dp[100001][3];
    int helper(string &s, string str, int n, int m){
        if(m==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        long long int res=0;
        if(s[n-1]==str[m-1]){
            res+=helper(s,str,n-1,m-1)+helper(s,str,n-1,m);
            res%=mod;
        }
        return dp[n][m]=(res+helper(s,str,n-1,m))%mod;
    }
    int fun(string &s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,"abc",s.size(),3);
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends