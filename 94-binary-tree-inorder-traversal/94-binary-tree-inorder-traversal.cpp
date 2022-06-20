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
    // void it(TreeNode *root, vector<int>&ans){
    //     if(root){
    //         it(root->left,ans);
    //         ans.push_back(root->val);
    //         it(root->right,ans);
    //     }
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     it(root,ans);
    //     return ans;
    // }
    
    //iterative
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> v;
    //     TreeNode *node = root;
    //     stack<TreeNode*>st;
    //     while(node!=NULL || st.size()!=0){
    //         while(node!=NULL){
    //             st.push(node);
    //             node=node->left;
    //         }
    //         node=st.top();
    //         st.pop();
    //         v.push_back(node->val);
    //         node=node->right;
    //     }
    //     return v;
    // }
    
    //morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        TreeNode *curr=root;
        while(curr){
            if(!curr->left){
                v.push_back(curr->val);
                curr=curr->right;
            }else{                
                TreeNode *prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;               
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    v.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return v;
    }    
};