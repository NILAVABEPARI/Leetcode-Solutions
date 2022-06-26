class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int len=edges.size();
        vector<int>inDegree(n,0),ans;
        for(int i=0;i<len;i++)
            inDegree[edges[i][1]]++;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) 
                ans.push_back(i);
        }
        return ans;
    }
};