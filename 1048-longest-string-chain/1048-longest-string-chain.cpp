class Solution {
public:
    // static bool comp(string &s1, string &s2){
    //     return s1.length()<s2.length();
    // }
    // bool check(string s1,string s2){
    //     int i=0,j=0,n=s1.length(),m=s2.length();
    //     if(n!=m+1) return false;
    //     while(i<n){
    //         if(s1[i]==s2[j]){
    //             i++;
    //             j++;
    //         }
    //         else i++;
    //     }
    //     return (i==n && j==m);
    // }
    // int LIS(vector<string>& nums){
    //     int n=nums.size();
    //     vector<int>dp(n,1);
    //     int maxi=1;
    //     for(int i=0;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             if(check(nums[i],nums[prev]) && 1+dp[prev]>dp[i])
    //                 dp[i]=1+dp[prev];
    //         }
    //         if(dp[i]>maxi) maxi=dp[i];
    //     }
    //     return maxi;
    // }
    // int longestStrChain(vector<string>& words){
    //     sort(words.begin(),words.end(),comp);
    //     return LIS(words);
    // }
    
    
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};