class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            int x=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({x,i});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            int i=pq.top().second;
            ans.push_back(points[i]);
            pq.pop();
        }
        return ans;
    }
};