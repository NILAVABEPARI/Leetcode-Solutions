class Solution {
public:
    int sqSum(int n){
        int sum=0;
        while(n){
            int x=n%10;
            sum+=x*x;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        st.insert(n);
        do{
            n=sqSum(n);
            if(st.count(n)) break;
            st.insert(n);
        }while(n!=1);
        return (n==1);
    }
};