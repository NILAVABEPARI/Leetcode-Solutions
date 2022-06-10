class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //better solution - o(2n)
        /*unordered_set<char>st;
        int maxi=0,l=0,r=0;
        while(r<s.length()){
            if(!st.count(s[r])){
                maxi=max(maxi, r-l+1);
                st.insert(s[r++]);
            }
            else{
                st.erase(s[l++]);
            }                            
        }        
        return maxi;*/
        
        
        //best - o(n)
        unordered_map<char,int>mp;
        int maxi=0,l=0,r=0;
        while(r<s.length()){
            if(mp.find(s[r]) != mp.end())
                l=max(l, mp[s[r]]+1);
            mp[s[r]]=r;
            maxi=max(maxi, r-l+1);
            r++;
        }        
        return maxi;
    }
};