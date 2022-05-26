class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     int N=m+n-2,R=n-1;
    //     double ans=1;
    //     for(int i=1;i<=R;i++)
    //         ans= (ans*(N-R+i))/i;
    //     return (int)ans;
    // }
    
    
    //memoization 
    // int f(int n,int m, vector<vector<int>>&dp){
    //     if(n==0 && m==0) return 1;
    //     if(n<0 || m<0) return 0;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     int u=f(n-1,m,dp);
    //     int l=f(n,m-1,dp);
    //     return dp[n][m]=u+l;
    // }
    // int uniquePaths(int m, int n){
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return f(m-1,n-1,dp);
    // }
    
    
    //tabulation
    // int uniquePaths(int m, int n){
    //     vector<vector<int>>dp(m,vector<int>(n,0));
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0) dp[0][0]=1;
    //             else{
    //                 int u = (i>0)?dp[i-1][j]:0;
    //                 int l = (j>0)?dp[i][j-1]:0;
    //                 dp[i][j]=u+l;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    
    
    //space optimization 
    int uniquePaths(int m, int n){
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=1;
                else{
                    int u = (i>0)?prev[j]:0;
                    int l = (j>0)?temp[j-1]:0;
                    temp[j]=u+l;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};