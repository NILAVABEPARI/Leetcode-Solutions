class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        int i=0;
        long temp=0;
        while(temp<n){
            temp=pow(4,i);
            i++;
        }
        return (temp==n);
    }
};