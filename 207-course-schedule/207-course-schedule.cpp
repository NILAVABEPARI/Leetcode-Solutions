class Solution {
public:
    //DFS algo
    // bool dfsRec(vector<vector<int>>&graph, vector<bool>&vis,  vector<bool>&recSt, int s){
    //     vis[s]=true;
    //     recSt[s]=true;
    //     for(int i:graph[s]){
    //         if(vis[i]==false && dfsRec(graph,vis,recSt,i))
    //             return true;
    //         else if(recSt[i]==true)
    //             return true;
    //     }
    //     recSt[s]=false;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& pre) {
    //     vector<vector<int>>graph(numCourses);
    //     int n=pre.size();
    //     for(int i=0;i<n;i++)
    //         graph[pre[i][1]].push_back(pre[i][0]);
    //     vector<bool>vis(numCourses,false),recSt(numCourses,false);
    //     for(int i=0;i<numCourses;i++){
    //         if(!vis[i] && dfsRec(graph,vis,recSt,i))
    //             return false;
    //     }
    //     return true;
    // }
    
    
    //BFS algo -- kahn's
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>graph(numCourses);
        int n=pre.size();
        for(int i=0;i<n;i++)
            graph[pre[i][1]].push_back(pre[i][0]);
        queue<int> q;
	    vector<int> indegree(numCourses);
	    for(int i = 0;i<numCourses;i++) {
	        for(auto it: graph[i])
	            indegree[it]++;
	    }
	    for(int i = 0;i<numCourses;i++) {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); q.pop(); 
	        cnt++; 
	        for(auto it : graph[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it); 
	        }
	    }
	    if(cnt == numCourses) return true; 
	    return false;
    }
};