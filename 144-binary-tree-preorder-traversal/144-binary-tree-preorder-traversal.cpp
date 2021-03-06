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
    // void pre(TreeNode *root, vector<int>&ans){
    //     if(root){
    //         ans.push_back(root->val);
    //         pre(root->left,ans);
    //         pre(root->right,ans);
    //     }
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     pre(root,ans);
    //     return ans;
    // }
    
    //iterative
    // vector<int> preorderTraversal(TreeNode* root){
    //     vector<int>ans;
    //     if(!root) return ans;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode *curr=st.top();
    //         st.pop();
    //         ans.push_back(curr->val);
    //         if(curr->right) st.push(curr->right);
    //         if(curr->left) st.push(curr->left);
    //     }
    //     return ans;
    // }
    
    
    //space optimized
    vector<int> preorderTraversal(TreeNode* root){
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        TreeNode *curr=root;
        while(curr!=NULL || !st.empty()){
            while(curr){
                ans.push_back(curr->val);
                if(curr->right) st.push(curr->right);
                curr=curr->left;
            }
            if(!st.empty()){
                curr=st.top();
                st.pop();
            }
        }
        return ans;
    }
};