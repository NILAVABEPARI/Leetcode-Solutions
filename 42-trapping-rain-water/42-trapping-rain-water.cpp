class Solution {
public:
    //better
    // int trap(vector<int>& height) {
    //     int n=height.size(),ans=0;
    //     vector<int>left(n),right(n);
    //     left[0]=height[0];
    //     right[n-1]=height[n-1];
    //     for(int i=1;i<n;i++)
    //         left[i]=max(left[i-1],height[i]);
    //     for(int i=n-2;i>=0;i--)
    //         right[i]=max(right[i+1],height[i]);
    //     for(int i=1;i<n-1;i++)
    //         ans+=min(left[i],right[i])-height[i];
    //     return ans;
    // }
    
    //optimal
    int trap(vector<int>& height){
        int n=height.size(),ans=0;
        int lm=0,rm=0,l=0,r=n-1;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>lm) lm=height[l];
                else ans+=lm-height[l];
                l++;
            }
            else{
                if(height[r]>rm) rm=height[r];
                else ans+=rm-height[r];
                r--;
            }
        }
        return ans;
    }
};