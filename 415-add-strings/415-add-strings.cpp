class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.length(),m=num2.length(),i=n-1,j=m-1,carry=0;
        string ans="";
        while(i>=0 && j>=0){
            int sum=(int)(num1[i--]-'0')+(int)(num2[j--]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        while(i>=0){
            int sum=(int)(num1[i--]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        while(j>=0){
            int sum=(int)(num2[j--]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        if(carry) ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};