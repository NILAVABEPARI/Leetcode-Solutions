// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
public:
    long long dfs(vector<vector<int>>&g, int curr, int par, int *cap){
        long long req=0,child=0;
        for(auto &it:g[curr]){
            if(it!=par){
                child++;
                long long chReq=dfs(g,it,curr,cap);
                if(chReq==-1) return -1;
                req=max(req,chReq);
            }
        }
        if((child*req)>(long long)1e18-cap[curr-1]) return -1;
        return child*req+cap[curr-1];
    }
    long long minimum_amount(vector<vector<int>> &edges, int N, int s, int *cap){
        // Code here
        vector<vector<int>> g(N+1);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(g , s , -1, cap);
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends