class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini=INT_MAX,n=strs.size();
        for(int i=0;i<n;i++){
            if(strs[i].length()<mini)
                mini=strs[i].length();
        }
        string ans="";
        for(int i=0;i<mini;i++){
            bool flag=true;
            for(int j=0;j<n-1;j++){                
                if(strs[j][i]!=strs[j+1][i]){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
            ans+=strs[0][i];
        }
        return ans;
    }
};