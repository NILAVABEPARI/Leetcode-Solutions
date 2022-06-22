// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
    //brute force
    // int spanningTree(int N, vector<vector<int>> adj[]){
    //     // code here
    //     vector<int>parent(N+1,-1); 
    //     vector<int>key(N+1,INT_MAX); 
    //     vector<bool>mstSet(N+1,false);
    //     key[0] = 0; 
    //     parent[0]=-1;
    //     for (int count = 0; count < N; count++){ 
    //         int mini = INT_MAX, u; 
    //         for (int v = 0; v < N; v++){
    //             if (mstSet[v] == false && key[v] < mini) {
    //                 mini = key[v];
    //                 u = v; 
    //             }
    //         }
    //         mstSet[u] = true; 
    //         for (auto it : adj[u]){
    //             int v = it[0];
    //             int weight = it[1];
    //             if (mstSet[v] == false && weight < key[v]) {
    //                 parent[v] = u;
    //                 key[v] = weight; 
    //             }
    //         }
    //     } 
    //     int sum=0;
    //     for (int i = 1; i <= N; i++){
    //         if(key[i] != INT_MAX)
    //             sum+=key[i];
    //     }
	   // return sum;
    // }
    
    
    //optimal
    int spanningTree(int N, vector<vector<int>> adj[]){
        vector<int>parent(N+1,-1); 
        vector<int>key(N+1,INT_MAX); 
        vector<bool>mstSet(N+1,false);
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        key[0] = 0; 
        parent[0] = -1; 
        pq.push({0, 0});
        while(!pq.empty()){ 
            int u = pq.top().second; 
            pq.pop();
            mstSet[u] = true;
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
    		        key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
        }
        int sum = 0;
        for(int i = 1;i<=N;i++) {
            if(key[i] != INT_MAX) sum += key[i];
        }
        return sum; 
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends