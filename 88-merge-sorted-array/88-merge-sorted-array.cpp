class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,n1=0,n2=0;
        vector<int> Nums1(nums1.begin(),nums1.begin()+m);        
        while(n1<m && n2<n){
            if(Nums1[n1]<nums2[n2])
                nums1[i++]=Nums1[n1++];
            else
                nums1[i++]=nums2[n2++];
        }
        while(n1<m){
            nums1[i++]=Nums1[n1++];
        }
        while(n2<n){
            nums1[i++]=nums2[n2++];
        }        
    }
};