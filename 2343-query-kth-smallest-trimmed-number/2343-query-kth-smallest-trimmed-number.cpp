class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size(),j=0;
        vector<int>ans;
        while(j<m){
            vector<pair<string,int>>temp;
            int strLen=nums[0].length();
            for(int i=0;i<n;i++)
                temp.push_back({nums[i].substr(strLen-queries[j][1]),i});
            // for(int i=0;i<n;i++)
            //     cout<<temp[i].first<<"-"<<temp[i].second<<" ";
            // cout<<endl;
            sort(temp.begin(),temp.end());
            ans.push_back(temp[queries[j][0]-1].second);
            j++;
        }
        return ans;
    }
};