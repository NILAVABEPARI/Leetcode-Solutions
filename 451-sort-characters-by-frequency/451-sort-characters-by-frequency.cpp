// struct myComp {
//     bool operator()(pair<char, int> const& a,pair<char, int> const& b){
//         return a.second < b.second;
//     }
// };
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int>mp;
//         for(auto it:s)
//             mp[it]++;
//         string ans="";
//         priority_queue<pair<char,int>,vector<pair<char,int>>,myComp>pq;
//         for(auto it:mp){
//             pq.push({it.first,it.second});
//         }
//         while(!pq.empty()){
//             int x=pq.top().second;
//             char c=pq.top().first;
//             while(x){
//                 ans+=c;
//                 x--;
//             }
//             pq.pop();
//         }
//         return ans;
//     }
// };




//without comparator
class Solution {
public:
    string frequencySort(string s){
        unordered_map<char,int>mp;
        for(auto it:s)
            mp[it]++;
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        while(!pq.empty()){
            int x=pq.top().first;
            while(x--)
                ans+=pq.top().second;
            pq.pop();
        }
        return ans;        
    }
};