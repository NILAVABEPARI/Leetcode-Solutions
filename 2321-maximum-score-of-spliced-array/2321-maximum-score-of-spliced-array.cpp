class Solution {
public:
    //apply kadanes algorithm
    int kadane(vector<int>&n1,vector<int>&n2){
        int res=0,sum=0,n=n1.size();
        for(int i=0;i<n;i++){
            sum+=n2[i]-n1[i];
            res=max(sum,res);
            if(sum<=0) sum=0;
        }
        return res;
    }
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        return max(accumulate(begin(n1),end(n1),0)+kadane(n1,n2),
                  accumulate(begin(n2),end(n2),0)+kadane(n2,n1));
    }
};