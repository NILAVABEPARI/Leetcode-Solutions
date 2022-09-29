class Solution {
public:
    //priority queue solution
    /*vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int n=arr.size();
        for(auto &it:arr)
            pq.push({abs(x-it),it});
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }*/
    
    
    
    //binary search solution
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        int l=0,r=arr.size()-k;
        while(l<r){
            int mid=(l+r)/2;
            if(x-arr[mid]>arr[mid+k]-x)
                l=mid+1;
            else r=mid;
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};