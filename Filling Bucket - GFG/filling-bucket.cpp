//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e8;

   long long int ad(long long int a, long long int b){

       return ((a%mod)+(b%mod))%mod;

   }

    int fillingBucket(int N) {

        // code here

        long long int dp[N];

        if(N<=2){

            return N;

        }

        dp[1] = 1;

        dp[2] = 2;

        for(int i = 3; i<=N; i++){

            dp[i] = ad((dp[i-1] % mod),(dp[i-2]%mod));

        }

        return dp[N];

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends