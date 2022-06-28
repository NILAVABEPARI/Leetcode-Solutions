class Solution {
public:
    int minDeletions(string s) {
        int n=s.length(),cnt=0;
        unordered_set<int>hasAppeared;
        int freq[26]={0};
        for(int i=0;i<n;i++) freq[s[i]-'a']++;
        sort(freq,freq+26);
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(hasAppeared.count(freq[i])==0)
                    hasAppeared.insert(freq[i]);
                else{
                    int j=1;
                    while(hasAppeared.count(freq[i]-j)!=0) j++;
                    cnt+=j;
                    freq[i]=freq[i]-j;
                    if(freq[i]!=0) hasAppeared.insert(freq[i]);
                }
            }                
        }        
        return cnt;
    }
};