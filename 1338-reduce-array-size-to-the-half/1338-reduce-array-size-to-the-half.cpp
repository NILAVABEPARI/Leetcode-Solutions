struct myComp {
    bool operator()(pair<int, int> const& a,pair<int, int> const& b){
        return a.second < b.second;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        for(auto &it:mp)
            pq.push({it.first,it.second});
        int cnt=0,len=0;
        bool flag=true;
        while(flag && !pq.empty()){
            len+=pq.top().second;
            //cout<<len<<" ";
            pq.pop();
            cnt++;
            if(len>=n/2) break;
        }
        return cnt;
    }
};