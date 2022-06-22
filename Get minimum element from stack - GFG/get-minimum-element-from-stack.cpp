// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
         int getMin(){
          if(!s.empty())
          return minEle;
          return -1;
      }
      
      /*returns poped element from stack*/
      int pop(){
          if(s.empty())
           return -1;
          
          if(s.top()>0){
              int x=s.top();
              s.pop();
              return x;
          }else{
             int curMin=minEle;
              minEle=minEle+abs(s.top());
              s.pop();
              return curMin;
          }
               
      }
      
      /*push element x into the stack*/
      void push(int x){
          if(s.empty()){
              minEle=x;
           s.push(x);
          }
          else if(minEle<=x){
              s.push(x);
          }
          else{
              int curMin=minEle;
              minEle=x;
              s.push(x-curMin);
          }
      }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends