struct compare {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2){
        return p1.second < p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto &it:mp)
            pq.push({it.first,it.second});        
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};