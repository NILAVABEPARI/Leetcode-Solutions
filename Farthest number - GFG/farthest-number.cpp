// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    //brute force
    // vector<int> farNumber(int n,vector<int> arr){
    //     //code here
    //     vector<int>ans(n);
    //     for(int i=0;i<n;i++){
    //         int j=n-1;
    //         while(j>i){
    //             if(arr[j]<arr[i]){
    //                 ans[i]=j; 
    //                 break;
    //             }
    //             j--;
    //         }
    //         if(j==i) ans[i]=-1;
    //     }
    //     return ans;
    // }
    
    vector<int> farNumber(int n,vector<int> arr){
        vector<int>ans(n,-1),suff(n);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=min(suff[i+1],arr[i]);
        
        for(int i=0;i<n;i++){
            int l=i+1,h=n-1,temp;
            while(l<=h){
                int mid=(h+l)/2;
                if(suff[mid]<arr[i]){
                    ans[i]=mid;
                    l=mid+1;
                }
                else
                    h=mid-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends