class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,maxi;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        maxi=sum;
        int low=n-1,high=k-1;
        while(high>=0){
            sum+=cardPoints[low];
            sum-=cardPoints[high];
            maxi=max(maxi,sum);
            low--;
            high--;
        }
        return maxi;
    }
};