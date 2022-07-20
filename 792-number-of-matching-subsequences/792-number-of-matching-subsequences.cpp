class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.length(),cnt=0;
        unordered_map<char,int>mp;
        for(auto &it:s) mp[it]++;
        sort(words.begin(),words.end());
        bool flag=true;
        for(int it=0;it<words.size();it++){
            if(it!=0 && words[it]==words[it-1] && !flag) continue;
            if(it!=0 && words[it]==words[it-1] && flag){
                cnt++;
                continue;
            }
            flag=false;
            int i=0,j=0,m=words[it].length();
            while(i<n && j<m){
                if(mp.count(words[it][j])==0) break;
                if(s[i]==words[it][j]) j++;
                i++;
            }
            if(i<=n && j==m){
                flag=true;
                cnt++;
            }
        }
        return cnt;
    }
};