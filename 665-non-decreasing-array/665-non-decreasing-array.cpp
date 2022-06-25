class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        vector<int>a(nums),b(nums);
        if(n==1) return true;
        int i=0;
        while(i<n-1 && nums[i]<=nums[i+1]) i++;
        if(i==n-1) return true;
        //either current element should be changed or the next element
        a[i]=a[i+1];
        b[i+1]=b[i];
        bool aCheck=true,bCheck=true;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]) 
                aCheck=false;
        }
        for(int i=0;i<n-1;i++){
            if(b[i]>b[i+1]) 
                bCheck=false;
        }
        return (aCheck || bCheck);
    }
};