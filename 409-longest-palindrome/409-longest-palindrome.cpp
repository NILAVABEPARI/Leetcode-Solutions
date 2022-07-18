class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
        }
        int ans=0,maxi=0;
        for(auto &it:mp){
            if(it.second%2==0) ans+=it.second;
            else{
                ans+=it.second-1;
                maxi=1;
            }
        }
        return ans+maxi;
    }
};