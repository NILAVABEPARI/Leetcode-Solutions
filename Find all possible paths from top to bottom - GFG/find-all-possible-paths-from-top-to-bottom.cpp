// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
  
   void solve(vector<vector<int>> grid, int x,int y,vector<int>v){
       // base case
       if(x==grid.size()-1 and y==grid[0].size()-1){
           v.push_back(grid[x][y]);
           ans.push_back(v);
           return;
       }
       
       
       // condition
       if(x!=grid.size()-1){
           v.push_back(grid[x][y]);
           solve(grid,x+1,y,v);
           v.pop_back();
       }
       
       if(y!=grid[0].size()-1){
           v.push_back(grid[x][y]);
           solve(grid,x,y+1,v);
           v.pop_back();
       }
       return;
   }
   vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
   {
       // code here
       vector<int>v;
       solve(grid,0,0,v);
       return ans;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends