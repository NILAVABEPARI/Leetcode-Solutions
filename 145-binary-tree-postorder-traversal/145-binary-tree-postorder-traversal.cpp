/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //recursive
    // void post(TreeNode *root, vector<int>&ans){
    //     if(root){
    //         post(root->left,ans);
    //         post(root->right,ans);
    //         ans.push_back(root->val);
    //     }
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     post(root,ans);
    //     return ans;
    // }
    
    //iterative -- using 2 stack
    // vector<int> postorderTraversal(TreeNode* root){
    //     vector<int>ans;
    //     if(!root) return ans;
    //     stack<TreeNode*>s1,s2;
    //     TreeNode *curr;
    //     s1.push(root);
    //     while(!s1.empty()){
    //         curr=s1.top();
    //         s1.pop();
    //         s2.push(curr);
    //         if(curr->left) s1.push(curr->left);
    //         if(curr->right) s1.push(curr->right);
    //     }
    //     while(!s2.empty()){
    //         curr=s2.top();
    //         s2.pop();
    //         ans.push_back(curr->val);
    //     }
    //     return ans;
    // }    
    
    //iterative -- using 1 stack
    vector<int> postorderTraversal(TreeNode* root){
        vector < int > postOrder;
        if (!root) return postOrder;
        stack < TreeNode * > st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root-> left;
            } 
            else {
                TreeNode * temp = st.top() -> right;
                if (!temp) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp -> val);
                    while (!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp -> val);
                    }
                } 
                else root = temp;
            }
        }
        return postOrder;
    }    
};