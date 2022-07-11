class Solution {
public:
    bool dfsRec(vector<vector<int>>&graph, vector<bool>&vis,  vector<bool>&recSt, int s){
        vis[s]=true;
        recSt[s]=true;
        for(int i:graph[s]){
            if(vis[i]==false && dfsRec(graph,vis,recSt,i))
                return true;
            else if(recSt[i]==true)
                return true;
        }
        recSt[s]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>graph(numCourses);
        int n=pre.size();
        for(int i=0;i<n;i++)
            graph[pre[i][1]].push_back(pre[i][0]);
        vector<bool>vis(numCourses,false),recSt(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && dfsRec(graph,vis,recSt,i))
                return false;
        }
        return true;
    }
};