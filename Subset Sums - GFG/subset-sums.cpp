// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
public:
    void recur(vector<int>&ans, vector<int>arr, int ind, int N, int sum){
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        recur(ans,arr,ind+1,N,sum);
        recur(ans,arr,ind+1,N,sum+arr[ind]);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        vector<int>ans;
        int sum=0;
        recur(ans,arr,0,N,sum);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends