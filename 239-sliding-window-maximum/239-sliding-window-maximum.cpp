class Solution {
public:
    //brute force -TLE - TC->O(N^2) SC->O(K)
    // void GetMax(vector < int > nums, int l, int r, vector < int > & arr) {
    //     int i, maxi = INT_MIN;
    //     for (i = l; i <= r; i++)
    //         maxi = max(maxi, nums[i]);
    //     arr.push_back(maxi);
    // }      
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector < int > maxSlidingWindow(vector < int > & nums, int k) {
    //     int left = 0, right = k-1;
    //     int i, j;
    //     vector < int > arr;
    //     while (right < nums.size()) {
    //         GetMax(nums, left, right, arr);
    //         left++;
    //         right++;
    //     }
    //     return arr;
    // }
        
    //brute force - TC->O(N) SC->O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();      
        for(int i=0;i<n;i++){
            //eliminate previous window's 1st element
            if(i>=k && !dq.empty() && dq.front()==nums[i-k]) dq.pop_front();
            
            //elimate numbers from back if present number is greater
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
            
            //push current element
            dq.push_back(nums[i]);     
            if(i>=k-1)
                ans.push_back(dq.front());
        }        
        return ans;
    }
};