// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
public:
    using ll = long long ; 
    vector<vector<int>> g ; 
    ll dfs(int u, int p, int *cap, int n){
       ll maxi = 0 ; 
       ll mini = 1e18 ;
       ll c = 0 ; 
       for(int& v : g[u]){
           if(v != p) {
               ll x = dfs(v , u , cap , n) ; 
               maxi = max(maxi , x) ; 
               mini = min(mini , x) ;
               c++ ; 
           }
       }
       if(mini == -1) return mini ; 
       if(cap[u - 1] > (ll)1e18 -  c * maxi) return -1 ;
       return cap[u - 1] + c*maxi ;
    }
    long long minimum_amount(vector<vector<int>> &edges, int n, int src, int *cap){
         g = vector<vector<int>>(n + 1) ;
         for(auto e : edges){
             g[e[0]].push_back(e[1]) ; 
             g[e[1]].push_back(e[0]) ; 
         }
         return dfs(src , src , cap , n) ; 
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