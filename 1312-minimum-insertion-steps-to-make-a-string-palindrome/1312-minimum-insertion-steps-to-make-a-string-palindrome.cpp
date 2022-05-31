class Solution {
public:
    //LPS    
    int lcs(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>prev(m+1,0);       
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }   
            prev=curr;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        return lcs(s,temp);
    }
    int minInsertions(string s) {
        int n=s.length(),m=longestPalindromeSubseq(s);
        return n-m;
    }
};