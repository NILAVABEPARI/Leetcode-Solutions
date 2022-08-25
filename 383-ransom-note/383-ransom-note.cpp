class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
            return false;
        unordered_map<char,int>mp;
        for(auto it:magazine)
            mp[it]++;        
        for(auto it:ransomNote){
            if(mp[it]!=0) mp[it]--;
            else return false;
        }
        return true;
    }
};