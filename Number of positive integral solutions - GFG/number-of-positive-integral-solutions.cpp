// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // long posIntSol(string s)
    
          long compute(int n,int value)
   {
        if(value>n) return (0);
       if(value> n-value) value=n-value;
       int dp[value+1];
       for(int i=0;i<=value;i++) { dp[i]=0; }
       dp[0]=1;
       for(int i=1;i<=n;i++)
       {
           for(int j=min(i,value);j>0;j--)
           {
               dp[j]=dp[j]+dp[j-1];
           }
       }
       return (dp[value]);
   }
   long posIntSol(string s)
   {
       int n=1,start=0; // for number of operands.
       
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='+')
               n+=1; //gives the total count of operands
           if(s[i]=='=')
               start=i;
       }
       string strvalue=s.substr(start+1);
       int value=stoi(strvalue);
       value-=1;
       n-=1;
       
       return (compute(value,n));
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends