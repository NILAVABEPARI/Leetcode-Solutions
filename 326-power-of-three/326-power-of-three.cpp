class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        int i=0;
        long temp=0;
        while(temp<n){
            temp=pow(3,i);
            i++;
        }
        return (temp==n);
    }
};