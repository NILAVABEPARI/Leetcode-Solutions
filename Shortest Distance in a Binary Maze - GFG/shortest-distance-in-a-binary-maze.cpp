//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        q.push(source);
        int ix = source.first, iy = source.second;
        if(ix==destination.first && iy==destination.second) return 0; // if src == dest
        vis[ix][iy] = 1;
        int steps = 0;
        int dx[] = {0, -1, 0, 1};
        int dy[] = {1, 0, -1, 0};
        bool found = false;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x==destination.first && y==destination.second){
                    found = true;
                    break;
                    return steps;
                }
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            if(found) break;
        }
        if(!found) return -1;
        return steps-1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends