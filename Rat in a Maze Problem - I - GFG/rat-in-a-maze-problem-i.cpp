// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void Solve(int i,int j,vector<vector<int>>&a,int n,vector<string>&ans,
                string moves,vector<vector<int>>&vis){
        if(vis[i][j]==1 || a[i][j]==0) return;
        if(i==n-1 && j==n-1){
            ans.push_back(moves);
            return;
        }
        vis[i][j]=1;
        if(i<n-1) Solve(i+1,j,a,n,ans,moves+"D",vis); //down
        if(j>0) Solve(i,j-1,a,n,ans,moves+"L",vis); //left
        if(j<n-1) Solve(i,j+1,a,n,ans,moves+"R",vis); //right
        if(i>0) Solve(i-1,j,a,n,ans,moves+"U",vis); //up
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return ans;
        string moves="";
        Solve(0,0,m,n,ans,moves,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends