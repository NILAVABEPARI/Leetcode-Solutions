class Solution {
public:
    string reverseWords(string s) {
        string rev=s;
        int counter=0,i=0;
        while(i<rev.length())
        {
            if(rev[i]==' ')
            {
                reverse(rev.begin()+counter, rev.begin()+i);
                counter=i+1;
            }
            i++;
        }
        reverse(rev.begin()+counter,rev.end());
        return rev;
    }
};