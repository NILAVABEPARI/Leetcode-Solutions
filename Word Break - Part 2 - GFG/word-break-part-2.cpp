// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(string s, string ans, unordered_set<string> &st, vector<string>& dict) {
        if(s.length() <= 0) {
            ans.pop_back();
            dict.push_back(ans);
        }
    
        for(int i = 0; i < s.length(); i++) {
            string left = s.substr(0,i+1);
    
            if(st.find(left) != st.end()) {
                solve(s.substr(i+1), ans + left + " ", st,dict);
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> st;
        for(string str : dict)
            st.insert(str);
        
        dict.clear();
        solve(s,"",st,dict);
        
        return dict;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends