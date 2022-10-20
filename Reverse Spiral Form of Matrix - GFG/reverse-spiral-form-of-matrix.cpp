//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&matrix)  {
        // code here
        int top=0,bottom=n-1,l=0,r=m-1;
        vector<int>ans;
        while(top<=bottom && l<=r){
            int i=l;
            while(i<=r){
                ans.push_back(matrix[top][i]);
                //cout<<matrix[top][i]<<" ";
                i++;
            }
            top++;
            i=top;
            while(i<=bottom){
                ans.push_back(matrix[i][r]);
                //cout<<matrix[i][r]<<" ";
                i++;
            }
            r--;
            i=r;
            if(top<=bottom){      
                while(i>=l){
                    ans.push_back(matrix[bottom][i]);
                    //cout<<matrix[bottom][i]<<" ";
                    i--;
                }
                bottom--;
            }
            i=bottom;
            if(l<=r){                 
                while(i>=top){
                    ans.push_back(matrix[i][l]);
                    //cout<<matrix[i][l]<<" ";
                    i--;
                }
                l++;    
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends