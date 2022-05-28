class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size(),j=0;
        vector<vector<int>> ans;
        unordered_map<int,vector<int>>mp;
        while(j<n){
            mp[groupSizes[j]].push_back(j);
            j++;
        }
        for(auto &it:mp){
            int m=it.second.size(),k=0,len=it.first;
            while(m){                
                vector<int>temp(len,0);                
                for(int i=0;i<len;i++)
                    temp[i]=it.second[k++];
                ans.push_back(temp);
                m-=it.first;
            }
        }
        return ans;
    }
};