/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        int n=temp.size();
        st.push(temp[n-1]);
        vector<int>ans(n);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=temp[i])
                st.pop();
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top();
            st.push(temp[i]);
        }
        return ans;
    }
};