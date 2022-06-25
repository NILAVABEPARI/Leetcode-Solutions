// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int countDistinctSubarray(int nums[], int n){
        //code here.
        unordered_map<int,int>mp;
        int i=0,cnt=0,j=0;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        int maxi=mp.size();
        mp.clear();
        for(j=0;j<n;j++){
            mp[nums[j]]++;
            while(mp.size()>=maxi && i<=j){
                cnt+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends