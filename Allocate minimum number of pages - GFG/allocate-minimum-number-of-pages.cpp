// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
    public:
    //Function to find minimum number of pages.
    bool isFeasable(int a[], int n, int k, int ans){
        int Count=1,sum=0;
        for(int i=0;i<n;i++){
            if(a[i]+sum>ans){
                Count++;
                sum=a[i];
            }
            else sum+=a[i];
        }
        return (Count<=k);
    }
    int findPages(int a[], int n, int m) {
        //code here
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            maxi=max(maxi,a[i]);
        }
        int low=maxi, high=sum, res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isFeasable(a,n,m,mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends