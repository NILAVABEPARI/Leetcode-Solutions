class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
        for(auto &it:sentence)
            st.insert(it);        
        return (st.size()==26);
    }
};