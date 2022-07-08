class Solution {
public:
    //using 2 vectors
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0),out(n+1,0);
        for(int i=0;i<trust.size();i++){
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(in[i]==n-1 && out[i]==0)
                ans=i;
        }
        return ans;
    }
    
    
    // in-degree - out-degree == n-1
    // int findJudge(int n, vector<vector<int>>& trust) {
    //     vector<int>deg(n+1,0);
    //     for(auto &it:trust){
    //         deg[it[1]]++;
    //         deg[it[0]]--;
    //     }
    //     int ans=-1;
    //     for(int i=1;i<=n;i++)
    //         if(deg[i]==n-1) return i;
    //     return -1;;
    // }
};